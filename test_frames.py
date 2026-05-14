import smbus2, numpy as np, time

addr = 0x33

for frame_num in range(3):
    bus = smbus2.SMBus(4)
    
    for _ in range(20):
        msg_w = smbus2.i2c_msg.write(addr, [0x80, 0x00])
        msg_r = smbus2.i2c_msg.read(addr, 2)
        bus.i2c_rdwr(msg_w, msg_r)
        val = (list(msg_r)[0]<<8)|list(msg_r)[1]
        if val & 0x0008:
            break
        time.sleep(0.1)

    msg_w = smbus2.i2c_msg.write(addr, [0x04, 0x00])
    msg_r = smbus2.i2c_msg.read(addr, 1536)
    bus.i2c_rdwr(msg_w, msg_r)
    data = list(msg_r)
    words = [(data[i]<<8)|data[i+1] for i in range(0,1536,2)]
    arr = np.array(words)
    print(f'Frame {frame_num}: Min={arr.min()} Max={arr.max()} Mean={arr.mean():.1f}')
    bus.close()
    time.sleep(1)
