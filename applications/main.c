/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-09     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "at24cxx.h"


int main(void)
{
    int count = 1;

    at24cxx_device_t dev;
    uint8_t read_buf[13]={0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
            0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c};

    LOG_D("%s", read_buf);
    dev = at24cxx_init("i2c1", 0);
    at24cxx_write(dev, 0, (uint8_t*)"laolidesenlin", 13);


    while (count++)
    {
        at24cxx_read(dev, 0, read_buf, 13);
        LOG_D("%s", read_buf);
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}
