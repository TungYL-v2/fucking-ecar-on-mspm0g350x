# 基于TI MSPM0G3507的智能小车模块程序

> 推荐学习B站大佬 [Torris-Yin](https://b23.tv/QHMCcdv)

本项目为基于 TI MSPM0G3507 微控制器的智能小车开发程序，使用 Keil MDK 进行开发。

## 分支说明

| 分支 | 说明 |
|------|------|
| **main** | 主分支，Keil MDK 工程（当前分支） |
| dev | 开发分支，Keil MDK 工程，实验性功能 |
| ccs_ver | CCS（Code Composer Studio）版本，不合入 main |
| 25E | 2025年电子设计竞赛E题赛时代码，CCS 工程 |

## 开发环境

- **微控制器**：MSPM0G3507（LQFP-64 封装）
- **主 IDE**：Keil MDK（工程文件：`empty_LP_MSPM0G3507_nortos_keil.uvprojx`）
- **编译器**：ARM Clang / TI CLANG
- **SDK**：TI MSPM0 SDK v2.00.01.00
- **配置工具**：SysConfig 1.20.0

## 目录结构

```
├── code/                                  # 应用层算法代码
│   ├── pid.c/h                            # PID 控制算法
│   ├── motor.c/h                          # 电机控制
│   ├── gray_track.c/h                     # 8路灰度循迹
│   └── filter.c/h                         # 信号滤波（卡尔曼滤波等）
├── ml_libs/                               # 外设驱动库
│   ├── oled_hardware_i2c.c/h              # OLED 显示屏驱动（I2C）
│   ├── ml_uart.c/h                        # UART 串口驱动
│   ├── ml_gpio.c/h                        # GPIO 驱动
│   ├── ml_pwm.c/h                         # PWM 驱动
│   ├── ml_tim.c/h                         # 定时器驱动
│   ├── ml_i2c.c/h                         # I2C 驱动
│   ├── ml_lsm6dsv16x.c/h                  # LSM6DSV16X IMU 驱动
│   └── ml_JY901S.c/h                      # JY901S 姿态传感器驱动
├── car_mspm0g3507/                        # CCS 工程目录
├── empty_LP_MSPM0G3507_nortos_ticlang/    # TI CLANG 工程目录
├── hardware_lsm_model/                    # LSM6DSV16X 硬件模型文件
├── ticlang/                               # TI CLANG 编译输出
├── main.c                                 # 主程序入口
├── isr.c                                  # 中断服务程序
├── car.syscfg                             # SysConfig 系统配置文件
├── ti_msp_dl_config.c/h                   # 外设初始化代码（SysConfig 自动生成）
├── mspm0g3507.sct                         # Keil 链接脚本
├── startup_mspm0g350x_uvision.s           # Keil 启动文件
└── keilkill.bat                           # 清理 Keil 中间文件的脚本
```

## 功能模块

### 电机控制
- PWM 控制直流减速电机速度
- 编码器反馈实现闭环速度控制
- PID 算法调节电机转速

### 灰度循迹
- 8路灰度传感器采集黑线位置
- 加权平均计算偏差值，驱动 PID 转向控制

### 传感器
- **LSM6DSV16X**：6轴 IMU（加速度计 + 陀螺仪），I2C 接口
- **JY901S**：9轴姿态传感器，UART 接口
- **OLED**：128×64 显示屏，I2C 接口，用于调试显示

### 通信
- UART0~UART2：串口通信，支持与上位机或其他模块通信

## 快速开始

1. 安装 [TI MSPM0 SDK v2.00.01.00](https://www.ti.com/tool/MSPM0-SDK)
2. 安装 [Keil MDK](https://www.keil.com/) 并配置 MSPM0G3507 支持包
3. 打开 `empty_LP_MSPM0G3507_nortos_keil.uvprojx`
4. 编译并通过 SWD 烧录到开发板