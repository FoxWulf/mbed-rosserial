#ifndef _ROS_std_msgs_Byte_h
#define _ROS_std_msgs_Byte_h

#include <stdint.h>
#include <cstring>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_msgs
{

  class Byte : public ros::Msg
  {
    public:
      typedef int8_t _data_type;
      _data_type data;

    Byte():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    virtual const char * getType() override { return "std_msgs/Byte"; };
    virtual const char * getMD5() override { return "ad736a2e8818154c487bb80fe42ce43b"; };

  };

}
#endif
