const { Board, ESC, Fn, Led } = require("johnny-five");
const keypress = require("keypress");
const board = new Board();

board.on("ready", () => {
  const led = new Led(13);
  const esc = new ESC({
    device: "FORWARD",
    controller: "DEFAULT",
    pwmRange: [1000, 2000],
    pin: 9,
  });
  let speed = 0;
  let last = null;

  // just to make sure the program is running
  led.blink(500);

  function controller(_, key) {
    let change = 0;

    if (!key) return;

    if (!key.shift) {
      change = esc.neutral;
      speed = 0;
    } else {
      switch(key.name) {
        case 'up':
          if (speed < 1000) speed += 1;
          break;
        case 'down':
          if (speed > 0) speed -= 1;
          break;
        case 'm':
          speed = 1000;
          break;
      }
      last = key.name;
    }

    change = esc.neutral + speed;
    console.clear();
    console.log("Key: ", key.name, key.shift);
    console.log("Neutral: ", esc.neutral);
    console.log("Change: ", change);
    console.log("Speed: ", speed);

    esc.throttle(change);
  }

  keypress(process.stdin);

  process.stdin.on("keypress", controller);
  process.stdin.setRawMode(true);
  process.stdin.resume();
});
