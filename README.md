arduino-accelerometer
=====================

Usage:
```
// Pass the pins which correspond to the X, Y, and Z axis to the constructor:
Accelerometer accel = Accelerometer(A2, A1, A0);

void loop() {
    accel.refresh();
    // refresh() determines the attitude of the accelerometer
    // You can then query it's position:
    //     accel.getX();
    // Or the change since the last time refresh() was called:
    //     accel.getDeltaX();
}
```

