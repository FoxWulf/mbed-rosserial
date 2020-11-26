/*
 * MbedHardware
 *
 *  Created on: Nov 19, 2020
 *      Author: Maximilian Müllner
 */

#ifndef ROS_MBED_HARDWARE_H_
#define ROS_MBED_HARDWARE_H_

#include "mbed.h"

#include "BufferedSerial.h"
#include <chrono>

class MbedHardware {
  public:
    MbedHardware(PinName tx, PinName rx, long baud = 115200) :iostream(tx, rx){
      baud_ = baud;
      t.start();

      // maybe add serial_port.set_format
      iostream.set_format(length_,BufferedSerial::None,0);
      
    }

    MbedHardware() : iostream(USBTX, USBRX) {
        baud_ = 115200;
        t.start();
    }

    void setBaud(long baud){
      this->baud_= baud;
    }

    int getBaud(){return baud_;}

    void init(){
        iostream.set_baud((baud_));
    }

    int read(){
        if (iostream.readable()) {
            return iostream.read(buffer_, length_);
        } else {
            return -1;
        }
    };
    void write(uint8_t* data, int length) {
        iostream.write(data, length);
    }

    unsigned long time(){return std::chrono::duration_cast<std::chrono::milliseconds>(t.elapsed_time()).count();}

protected:
    BufferedSerial iostream;
    long baud_;
    int* buffer_;
    size_t length_ = 8;
    Timer t;
};


#endif /* ROS_MBED_HARDWARE_H_ */
