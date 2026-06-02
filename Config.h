/* ---------------------------------------------------------------------------------------------------------------------------------
 * OnStepX 配置文件
 *
 *          关于 OnStep 的配置详情请参见 http://www.stellarjourney.com/index.php?r=site/equipment_onstep 
 *                      并加入 OnStep Groups.io 群组：https://groups.io/g/onstep
 * 
 *           *** 阅读编译器的警告和错误信息，它们用于帮助防止无效配置 ***
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
 * 调整以下内容以配置你的控制器功能 ----------------------------------------------------------------------
 * <-必须项 = 始终必须设置, <-常用项 = 通常需要设置, 可选项 = 可选, 调整项 = 根据需要调整, 不常用 = 极少修改
*/
//      参数名称                   取值   默认值  说明                                                                        提示

// =================================================================================================================================
// 控制器 ======================================================================================================================
#define HOST_NAME                "OnStep" // 设备主机名，最多16个字符。                                           调整项

// 引脚定义 --------------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Controller#PINMAP
#define PINMAP                        MaxESP4 // 关闭，选择：MiniPCB, MiniPCB2, MaxPCB4, MaxESP4, MaxSTM3, FYSETC_E4,   必须项
                                          //         BTT_SKR_PRO 等。更多主板信息详见 ~/src/Constants.h

// 串口命令通道 ------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Controller#SERIAL_PORTS
#define SERIAL_A_BAUD_DEFAULT        9600 // 9600，波特率：9600,19200,57600,115200,230400,460800（常用波特率）    不常用
#define SERIAL_B_BAUD_DEFAULT        9600 // 9600，同上波特率。串口分配详见 (src/pinmaps/)                     不常用
#define SERIAL_B_ESP_FLASHING         OFF // 关闭，开启后通过 SERIAL_B 使用 :ESPFLASH# 命令上传 ESP8266 WiFi 固件  可选项
#define SERIAL_C_BAUD_DEFAULT         OFF // 关闭，同上波特率。串口分配详见 (src/pinmaps/)                     不常用
#define SERIAL_D_BAUD_DEFAULT         OFF // 关闭，同上波特率。串口分配详见 (src/pinmaps/)                     不常用
#define SERIAL_E_BAUD_DEFAULT         OFF // 关闭，同上波特率。串口分配详见 (src/pinmaps/)                     不常用
#define SERIAL_RADIO                  OFF // 关闭，使用蓝牙 或 WiFi 接入点/工作站模式（仅 ESP32）              可选项

// 状态指示灯 ----------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Controller#STATUS_LED
#define STATUS_LED                    OFF // 关闭，无错误时常亮，有错误时闪烁错误代码。                           可选项

// 分划板照明控制 ------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Controller#RETICLE_CONTROL
#define RETICLE_LED_DEFAULT           OFF // 关闭，0-255（0-100%亮度）启用该功能并设置默认亮度。                可选项
#define RETICLE_LED_MEMORY            OFF // 关闭，开启后断电记忆分划板亮度。                                    可选项
#define RETICLE_LED_INVERT            OFF // 关闭，开启后反转控制（0V为最大亮度时使用）。                         可选项

// 气象传感器 --------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Controller#WEATHER_SENSOR
#define WEATHER                       OFF // 关闭，BME280 (I2C 0x77), BME280_0x76, BME280_SPI（CS引脚见引脚定义） 可选项
                                          //         BMP280 (I2C 0x77), BMP280_0x76, BMP280_SPI（CS引脚见引脚定义）
                                          //         BME280/BMP280 支持温度、气压。BME280 额外支持湿度。

// 信号模式 ------------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Controller#SIGNALING
#define STEP_WAVE_FORM             SQUARE // 方波，脉冲波形适用于高速。方波信号完整性最佳。                      调整项
                                          //         适用于所有轴

// 非易失性存储器 ---------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Controller#NV
#define NV_DRIVER              NV_DEFAULT // 默认，使用平台默认非易失性存储设备保存运行参数。                     可选项

// =================================================================================================================================
// 赤道仪/云台 ===================================================================================================================

// 驱动型号（步进/方向 & 伺服）多数有特定要求，务必参考下方链接了解详情。
// 常用：A4988, DRV8825, LV8729, S109, TMC2130, TMC5160, TMC2209 等。

// 轴1 赤经/方位 -------------------------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Axes
#define AXIS1_DRIVER_MODEL            TMC2209 // 关闭，两个轴都填写驱动型号才能激活赤道仪。                          常用项

// 如果启用了运行时轴参数设置，以下内容将被忽略（可在SWS中禁用或清除NV/EEPROM）：
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ 
#define AXIS1_STEPS_PER_DEGREE      12800 // 12800，每度步数：                                                      必须项
                                          // 计算公式：(电机步数 * 细分数 * 总减速比)/360.0
#define AXIS1_REVERSE                 OFF // 关闭，开启反转运动方向，也可通过反转接线修正。                       常用项
#define AXIS1_LIMIT_MIN              -180 // -180，-90~-360（度）。最小时角或方位角。                             调整项
#define AXIS1_LIMIT_MAX               180 // 180，90~360（度）。最大时角或方位角。                                调整项
#define AXIS1_LIMIT_SYNC              OFF // 关闭，0~90（度）。仅允许在该范围内同步/复位。                        可选项

#define AXIS1_DRIVER_MICROSTEPS       OFF // 关闭，默认细分数。                                                    必须项
#define AXIS1_DRIVER_MICROSTEPS_GOTO  OFF // 关闭，GOTO 模式细分数。关闭则使用默认细分数。                        可选项

// TMC2130/TMC5160/TMC2209/TMC2226 步进驱动专用：
#define AXIS1_DRIVER_IHOLD            OFF // 关闭，待机电流（毫安）。关闭则使用 IRUN/2.0                          可选项
#define AXIS1_DRIVER_IRUN             OFF // 关闭，运行电流（毫安）。根据电机/驱动设置。                          可选项
#define AXIS1_DRIVER_IGOTO            OFF // 关闭，GOTO 运行电流（毫安）。关闭则使用 IRUN。                        可选项
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS1_DRIVER_STATUS           OFF // 关闭，开启/高电平/低电平。驱动状态信息/故障检测。                     可选项

#define AXIS1_DRIVER_DECAY            OFF // 关闭，跟踪模式衰减模式。TMC 默认静音斩波模式。                        不常用
#define AXIS1_DRIVER_DECAY_GOTO       OFF // 关闭，GOTO 模式衰减模式。TMC 默认扩频周期模式。                        不常用

#define AXIS1_POWER_DOWN              OFF // 关闭，开启后停止运动30秒或导星≤1倍速10分钟后断电。                    不常用

#define AXIS1_SENSE_HOME              OFF // 关闭，高/低电平启用，从正面看顺时针为原点位置。                       可选项
#define AXIS1_SENSE_LIMIT_MIN LIMIT_SENSE // 限位检测，高/低电平限位开关触发时停止运动。                          可选项
#define AXIS1_SENSE_LIMIT_MAX LIMIT_SENSE // 限位检测，高/低电平限位开关触发时停止运动。                          可选项
                                          // 数字信号可加：|HYST(n) n=0~1023 稳定时间（毫秒）
                                          // 模拟信号可加：
                                          // |THLD(n) n=1~1023 模拟阈值
                                          // |HYST(n) n=0~1023 滞后范围

// 轴2 赤纬/高度 ------------------------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Axes
#define AXIS2_DRIVER_MODEL            TMC2209 // 关闭，两个轴都填写驱动型号才能激活赤道仪。                          常用项

// 如果启用了运行时轴参数设置，以下内容将被忽略（可在SWS中禁用或清除NV/EEPROM）：
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
#define AXIS2_STEPS_PER_DEGREE      12800 // 12800，每度步数：                                                      必须项
                                          // 计算公式：(电机步数 * 细分数 * 总减速比)/360.0
#define AXIS2_REVERSE                 OFF // 关闭，开启反转运动方向，也可通过反转接线修正。                       常用项
#define AXIS2_LIMIT_MIN               -90 // -90，-90~0（度）。最小赤纬或高度。                                   不常用
#define AXIS2_LIMIT_MAX                90 // 90，0~90（度）。最大赤纬或高度。                                      不常用
#define AXIS2_LIMIT_SYNC              OFF // 关闭，0~90（度）。仅允许在该范围内同步/复位。                        可选项

#define AXIS2_DRIVER_MICROSTEPS       OFF // 关闭，默认细分数。                                                    必须项
#define AXIS2_DRIVER_MICROSTEPS_GOTO  OFF // 关闭，GOTO 模式细分数。关闭则使用默认细分数。                        可选项

// TMC2130/TMC5160/TMC2209/TMC2226 步进驱动专用：
#define AXIS2_DRIVER_IHOLD            OFF // 关闭，待机电流（毫安）。关闭则使用 IRUN/2.0                          可选项
#define AXIS2_DRIVER_IRUN             OFF // 关闭，运行电流（毫安）。根据电机/驱动设置。                          可选项
#define AXIS2_DRIVER_IGOTO            OFF // 关闭，GOTO 运行电流（毫安）。关闭则使用 IRUN。                        可选项
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS2_DRIVER_STATUS           OFF // 关闭，开启/高电平/低电平。驱动状态信息/故障检测。                     可选项

#define AXIS2_DRIVER_DECAY            OFF // 关闭，跟踪模式衰减模式。TMC 默认静音斩波模式。                        不常用
#define AXIS2_DRIVER_DECAY_GOTO       OFF // 关闭，GOTO 模式衰减模式。TMC 默认扩频周期模式。                        不常用

#define AXIS2_POWER_DOWN              OFF // 关闭，开启后停止运动30秒或导星≤1倍速10分钟后断电。                    可选项

#define AXIS2_SENSE_HOME              OFF // 关闭，高/低电平启用，从上方看顺时针为原点位置。                       可选项
#define AXIS2_SENSE_LIMIT_MIN LIMIT_SENSE // 限位检测，高/低电平限位开关触发时停止运动。                          可选项
#define AXIS2_SENSE_LIMIT_MAX LIMIT_SENSE // 限位检测，高/低电平限位开关触发时停止运动。                          可选项

// 赤道仪类型 ------------------------------------------------ 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#MOUNT
#define MOUNT_TYPE                    GEM // GEM，德国式赤道仪（需要子午线翻转）等。                             必须项
                                          // GEM_TA     带切臂赤纬的德国赤道仪
                                          // GEM_TAC    带切臂赤纬和几何修正的德国赤道仪
                                          // FORK       叉式赤道仪
                                          // FORK_TA    带切臂赤纬的叉式赤道仪
                                          // FORK_TAC   带切臂赤纬和几何修正的叉式赤道仪
                                          // ALTAZM     地平式云台/道布森望远镜
                                          // ALTAZM_UNL 无限方位角运动的地平式云台

#define MOUNT_ALTERNATE_ORIENTATION   OFF // 关闭，开启后叉式赤道仪支持子午线翻转，地平式云台可过天顶。GEM模式忽略  可选项

#define MOUNT_STARTUP_MODE        SA_AUTO // 自动，严格/许可模式。控制启动信任权限。                               可选项
                                          // 无绝对位置源且坐标记忆关闭时，自动保持传统立即GOTO模式

#define MOUNT_COORDS          TOPOCENTRIC // 测地坐标，对进出OnStep的坐标应用大气折射修正（极点除外）               不常用
                                          // TOPO_STRICT 极点也应用折射修正
                                          // OBSERVED_PLACE 不应用折射修正

#define MOUNT_COORDS_MEMORY           OFF // 关闭，开启后断电记忆赤道仪坐标。                                       可选项
                                          // 需要FRAM非易失性存储，且断电时赤道仪不能移动

#define MOUNT_ENABLE_IN_STANDBY       OFF // 关闭，开启后待机时保持电机驱动供电。                                 不常用

// 时间与位置 ------------------------ 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#TLS
#define TIME_LOCATION_SOURCE          DS3231 // 关闭，DS3231(I2C), SD3031(I2C), TEENSY, GPS, NTP 时间来源。            可选项
                                          // 提供日期/时间，支持的话还提供秒脉冲、经纬度

#define TIME_LOCATION_PPS_SENSE       OFF // 关闭，高电平检测秒脉冲上升沿，低电平为下降沿，双沿为两者              可选项

// 状态指示 -------------------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#STATUS
#define STATUS_MOUNT_LED              ON  // 关闭，开启后随运动频率闪烁，GOTO时常亮。                              可选项
#define STATUS_BUZZER                 OFF // 关闭，开启/100~6000Hz 蜂鸣器频率。开启为压电蜂鸣器。                   可选项
#define STATUS_BUZZER_DEFAULT         OFF // 关闭，开启后默认启动蜂鸣音效。                                         可选项
#define STATUS_BUZZER_MEMORY          OFF // 关闭，开启后断电记忆蜂鸣音效设置。                                    可选项

// ST4 接口 -------------------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#ST4
// *** 你需自行确认接口电气规格符合外接设备要求，风险自担 ***
#define ST4_INTERFACE                 OFF // 关闭，开启启用接口。手动模式下≤1倍导星，GOTO时按键：中止/继续翻转      可选项
#define ST4_HAND_CONTROL               ON // 开启，手控器特殊功能和SHC支持。                                       可选项
                                          // 长按[东]+[西]>2秒：导星速度 [东]- [西]+ [北]跟踪开关 [南]同步
                                          // 长按[北]+[南]>2秒：用户天体 [东]- [西]+ [北]GOTO [南]音效开关
#define ST4_HAND_CONTROL_FOCUSER       ON // 开启，替代模式：调焦控制 [东]焦1 [西]焦2 [北]- [南]+                  可选项

// 导星行为 ------------------------------------------ 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#GUIDING
#define GUIDE_TIME_LIMIT               10 // 10，0~120秒。导星时间限制，0禁用。                                    调整项
#define GUIDE_DISABLE_BACKLASH        OFF // 关闭，≤1倍导星时禁用间隙补偿。                                         可选项

// 限位保护 -------------------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#LIMITS
#define LIMIT_SENSE                   OFF // 关闭，高/低电平限位开关触发时停止运动。                              可选项
#define LIMIT_STRICT                  OFF // 关闭，解位GOTO/同步前禁用限位。开启则启动时启用限位。                  可选项
                                          // 开启后日期/时间设置前禁止所有运动

// 归位功能 ---------------------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#PARKING
#define PARK_SENSE                    OFF // 关闭，高/低电平指示赤道仪已归位。                                     可选项
#define PARK_SIGNAL                   OFF // 关闭，高/低电平归位信号触发自动归位。                                 可选项
#define PARK_STATUS                   OFF // 关闭，成功归位后输出高/低电平信号。                                   可选项

// 周期误差校正 ------------------------------------------------ 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#PEC
#define PEC_STEPS_PER_WORM_ROTATION     0 // 0，蜗杆每转步数（0禁用，否则分配720秒缓冲区）。                      必须项
                                          // 计算公式：(AXIS1_STEPS_PER_DEGREE*360)/末级减速比

#define PEC_SENSE                     OFF // 关闭，高电平检测PEC信号上升沿，低电平为下降沿。地平模式忽略。           可选项
#define PEC_BUFFER_SIZE_LIMIT         720 // 720，PEC缓冲区最大秒数。                                             不常用

// 跟踪行为 ---------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#TRACKING
#define TRACK_BACKLASH_RATE            20 // 20，2~50倍恒星速度。间隙补偿速度。                                     可选项
                                          // 过快电机会堵转/齿轮撞击，过慢间隙补偿迟缓

#define TRACK_AUTOSTART               OFF // 关闭，开启后启动自动跟踪。                                           可选项
#define TRACK_COMPENSATION_DEFAULT    OFF // 关闭，无补偿，或折射/双折射/模型/双模型补偿。                        可选项
#define TRACK_COMPENSATION_MEMORY     OFF // 关闭，开启后记忆跟踪补偿设置。                                       可选项

// 旋转行为 ------------------------------------------ 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#SLEWING
#define SLEW_RATE_BASE_DESIRED        1.0 // 1.0，目标旋转速度（度/秒）。运行时可在1/2~2倍间调节。                  必须项
#define SLEW_RATE_MEMORY              OFF // 关闭，开启后断电记忆旋转速度。                                       可选项
#define SLEW_ACCELERATION_DIST        5.0 // 5.0，加减速距离（度）。                                             调整项
#define SLEW_RAPID_STOP_DIST          2.0 // 2.0，旋转中止/限位触发时的急停距离（度）。                            调整项
#define GOTO_FEATURE                   ON // 开启，关闭禁用GOTO功能。                                             不常用
#define GOTO_OFFSET                  0.25 // 0.25，GOTO目标单向逼近偏移量（度），0禁用。                           调整项
#define GOTO_OFFSET_ALIGN             OFF // 关闭，开启后校准星跳过GOTO最后阶段，方便用户从正确方向校准星体。       可选项

// 镜腿侧行为 --------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#PIERSIDE
#define MFLIP_SKIP_HOME               OFF // 关闭，开启后直接前往目标，不经过原点。                               可选项
#define MFLIP_AUTOMATIC_DEFAULT       OFF // 关闭，开启后启动自动子午线翻转。                                     可选项
#define MFLIP_AUTOMATIC_MEMORY        OFF // 关闭，开启后断电记忆自动翻转设置。                                   可选项
#define MFLIP_PAUSE_HOME_DEFAULT      OFF // 关闭，开启后子午线翻转时在原点暂停。                                 不常用
#define MFLIP_PAUSE_HOME_MEMORY       OFF // 关闭，开启后断电记忆翻转暂停设置。                                   不常用

#define PIER_SIDE_SYNC_CHANGE_SIDES   OFF // 关闭，开启后同步可切换镜腿侧（GEM专用）。                            可选项
#define PIER_SIDE_PREFERRED_DEFAULT  BEST // 最佳，优先保持当前侧。东/西模式可自动切换。                          可选项
                                          // 自动模式：近极下子午线优先西侧，否则东侧
#define PIER_SIDE_PREFERRED_MEMORY    OFF // 关闭，开启后断电记忆镜腿侧设置。                                   可选项

// 校准功能 ------------------------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Mount#ALIGN
#define ALIGN_AUTO_HOME               OFF // 关闭，开启后校准时先通过原点开关找原点。                             可选项
#define ALIGN_MODEL_MEMORY            OFF // 关闭，开启后启动恢复存储的指向模型。                                 可选项
#define ALIGN_MAX_STARS              AUTO // 自动，使用硬件默认值（6或9颗星）。                                    不常用
                                          // 或手动设置：1（仅同步）、3~9（GOTO辅助）

// =================================================================================================================================
// 旋转器 ========================================================================================================================

// 驱动型号（步进/方向 & 伺服）多数有特定要求，务必参考下方链接了解详情。
// 常用：A4988, DRV8825, LV8729, S109, TMC2130S 等。

// 轴3 场旋器 ----------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Rotator
#define AXIS3_DRIVER_MODEL            OFF // 关闭，填写驱动型号激活旋转器。                                       可选项
#define AXIS3_SLEW_RATE_BASE_DESIRED  1.0 // 1.0，目标旋转速度（度/秒）。运行时可在1/2~2倍间调节。                  必须项

// 如果启用了运行时轴参数设置，以下内容将被忽略（可在SWS中禁用或清除NV/EEPROM）：
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
#define AXIS3_STEPS_PER_DEGREE       64.0 // 64.0，旋转器/消旋器每度步数。                                        调整项
                                          // 地平消旋：n=(圆周像素数*2)/360，最小值
#define AXIS3_REVERSE                 OFF // 关闭，开启反转运动方向，也可通过反转接线修正。                       可选项
#define AXIS3_LIMIT_MIN                 0 // 0，-360~0（度）。最小旋转角度。                                       不常用
#define AXIS3_LIMIT_MAX               360 // 360，0~360（度）。最大旋转角度。                                      不常用

#define AXIS3_DRIVER_MICROSTEPS       OFF // 关闭，默认细分数。                                                    可选项
#define AXIS3_DRIVER_MICROSTEPS_GOTO  OFF // 关闭，GOTO 模式细分数。关闭则使用默认细分数。                        可选项

// TMC2130/TMC5160/TMC2209/TMC2226 步进驱动专用：
#define AXIS3_DRIVER_IHOLD            OFF // 关闭，待机电流（毫安）。关闭则使用 IRUN/2.0                          可选项
#define AXIS3_DRIVER_IRUN             OFF // 关闭，运行电流（毫安）。根据电机/驱动设置。                          可选项
#define AXIS3_DRIVER_IGOTO            OFF // 关闭，GOTO 运行电流（毫安）。关闭则使用 IRUN。                        可选项
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS3_DRIVER_STATUS           OFF // 关闭，开启/高电平/低电平。驱动状态信息/故障检测。                     可选项

#define AXIS3_DRIVER_DECAY            OFF // 关闭，跟踪模式衰减模式。TMC 默认静音斩波模式。                        不常用
#define AXIS3_DRIVER_DECAY_GOTO       OFF // 关闭，GOTO 模式衰减模式。TMC 默认扩频周期模式。                        不常用

#define AXIS3_POWER_DOWN              OFF // 关闭，开启后停止运动30秒后断电。                                       可选项

#define AXIS3_SENSE_HOME              OFF // 关闭，高/低电平启用，从上方看顺时针为原点位置。                       可选项
#define AXIS3_SENSE_LIMIT_MIN         OFF // 关闭，高/低电平限位开关触发时停止运动。                              可选项
#define AXIS3_SENSE_LIMIT_MAX         OFF // 关闭，高/低电平限位开关触发时停止运动。                              可选项

// =================================================================================================================================
// 调焦器 ========================================================================================================================

// 驱动型号（步进/方向 & 伺服）多数有特定要求，务必参考下方链接了解详情。
// 常用：A4988, DRV8825, LV8729, S109, TMC2130S 等。

// 轴4 调焦器1 ------------------------详见 https://onstep.groups.io/g/main/wiki/Configuration_Focuser
#define AXIS4_DRIVER_MODEL            OFF // 关闭，填写驱动型号激活调焦器。                                       可选项
#define AXIS4_SLEW_RATE_BASE_DESIRED  500 // 500，200~5000（微米/秒）。运行时可在1/2~2倍间调节。                    必须项
#define AXIS4_SLEW_RATE_MINIMUM        20 // 20，5~200（微米/秒）。最小速度。                                     调整项

// 如果启用了运行时轴参数设置，以下内容将被忽略（可在SWS中禁用或清除NV/EEPROM）：
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
#define AXIS4_STEPS_PER_MICRON        0.5 // 0.5，每微米步数。通过测试计算得出。                                 调整项
#define AXIS4_REVERSE                 OFF // 关闭，开启反转运动方向，也可通过反转接线修正。                       可选项
#define AXIS4_LIMIT_MIN                 0 // 0，0~500（毫米）。最小位置。                                          调整项
#define AXIS4_LIMIT_MAX                50 // 50，0~500（毫米）。最大位置。                                          调整项

#define AXIS4_DRIVER_MICROSTEPS       OFF // 关闭，默认细分数。                                                    可选项
#define AXIS4_DRIVER_MICROSTEPS_GOTO  OFF // 关闭，GOTO 模式细分数。关闭则使用默认细分数。                        可选项

// TMC2130/TMC5160/TMC2209/TMC2226 步进驱动专用：
#define AXIS4_DRIVER_IHOLD            OFF // 关闭，待机电流（毫安）。关闭则使用 IRUN/2.0                          可选项
#define AXIS4_DRIVER_IRUN             OFF // 关闭，运行电流（毫安）。根据电机/驱动设置。                          可选项
#define AXIS4_DRIVER_IGOTO            OFF // 关闭，GOTO 运行电流（毫安）。关闭则使用 IRUN。                        可选项
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS4_DRIVER_STATUS           OFF // 关闭，开启/高电平/低电平。驱动状态信息/故障检测。                     可选项

#define AXIS4_DRIVER_DECAY            OFF // 关闭，跟踪模式衰减模式。TMC 默认静音斩波模式。                        不常用
#define AXIS4_DRIVER_DECAY_GOTO       OFF // 关闭，GOTO 模式衰减模式。TMC 默认扩频周期模式。                        不常用

#define AXIS4_POWER_DOWN              OFF // 关闭，开启后停止运动30秒后断电。                                       可选项

#define AXIS4_SENSE_HOME              OFF // 关闭，高/低电平启用，从上方看顺时针为原点位置。                       可选项
#define AXIS4_SENSE_LIMIT_MIN         OFF // 关闭，高/低电平限位开关触发时停止运动。                              可选项
#define AXIS4_SENSE_LIMIT_MAX         OFF // 关闭，高/低电平限位开关触发时停止运动。                              可选项

// 轴5 调焦器2 -----------------------------------------------------------------------------------------------------------------
// 最多支持6个调焦器（轴4-轴9），复制轴4代码并重命名为轴5即可

// 调焦器温度 ------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Focuser
#define FOCUSER_TEMPERATURE           OFF // 关闭，热敏电阻 或 DS18B20 序列号。                                 调整项

// =================================================================================================================================
// 辅助功能 ======================================================================================================================

// 功能配置 --------------------------- 详见 https://onstep.groups.io/g/main/wiki/Configuration_Aux
// 注意：临时设置调试模式为详细输出，使用 "FEATURE1_TEMP DS1820" 列出 DS18B20 序列号

#define FEATURE1_PURPOSE              OFF // 关闭，开关、瞬时开关、模拟输出、除雾加热器、间隔计。                   可选项
#define FEATURE1_NAME          "FEATURE1" // 功能名称                                                             调整项
#define FEATURE1_TEMP                 OFF // 关闭，热敏电阻 或 DS18B20 序列号。除雾加热器温度传感器。              调整项
#define FEATURE1_PIN                  OFF // 关闭，辅助引脚 或 引脚编号。                                         调整项
#define FEATURE1_VALUE_DEFAULT        OFF // 关闭，开启/0~255（模拟输出）。                                       调整项
#define FEATURE1_VALUE_MEMORY         OFF // 关闭，开启后断电记忆状态。                                           调整项
#define FEATURE1_ON_STATE            HIGH // 高电平，低电平反转（开启=0V，关闭=Vcc通常3.3V）。                     调整项

#define FEATURE2_PURPOSE              OFF // 关闭，开关、瞬时开关、模拟输出、除雾加热器、间隔计。                   可选项
#define FEATURE2_NAME          "FEATURE2" // 功能名称                                                             调整项
#define FEATURE2_TEMP                 OFF // 关闭，热敏电阻 或 DS18B20 序列号。除雾加热器温度传感器。              调整项
#define FEATURE2_PIN                  OFF // 关闭，辅助引脚 或 引脚编号。                                         调整项
#define FEATURE2_VALUE_DEFAULT        OFF // 关闭，开启/0~255（模拟输出）。                                       调整项
#define FEATURE2_VALUE_MEMORY         OFF // 关闭，开启后断电记忆状态。                                           调整项
#define FEATURE2_ON_STATE            HIGH // 高电平，低电平反转（开启=0V，关闭=Vcc通常3.3V）。                     调整项

#define FEATURE3_PURPOSE              OFF // 关闭，开关、瞬时开关、模拟输出、除雾加热器、间隔计。                   可选项
#define FEATURE3_NAME          "FEATURE3" // 功能名称                                                             调整项
#define FEATURE3_TEMP                 OFF // 关闭，热敏电阻 或 DS18B20 序列号。除雾加热器温度传感器。              调整项
#define FEATURE3_PIN                  OFF // 关闭，辅助引脚 或 引脚编号。                                         调整项
#define FEATURE3_VALUE_DEFAULT        OFF // 关闭，开启/0~255（模拟输出）。                                       调整项
#define FEATURE3_VALUE_MEMORY         OFF // 关闭，开启后断电记忆状态。                                           调整项
#define FEATURE3_ON_STATE            HIGH // 高电平，低电平反转（开启=0V，关闭=Vcc通常3.3V）。                     调整项

#define FEATURE4_PURPOSE              OFF // 关闭，开关、瞬时开关、模拟输出、除雾加热器、间隔计。                   可选项
#define FEATURE4_NAME          "FEATURE4" // 功能名称                                                             调整项
#define FEATURE4_TEMP                 OFF // 关闭，热敏电阻 或 DS18B20 序列号。除雾加热器温度传感器。              调整项
#define FEATURE4_PIN                  OFF // 关闭，辅助引脚 或 引脚编号。                                         调整项
#define FEATURE4_VALUE_DEFAULT        OFF // 关闭，开启/0~255（模拟输出）。                                       调整项
#define FEATURE4_VALUE_MEMORY         OFF // 关闭，开启后断电记忆状态。                                           调整项
#define FEATURE4_ON_STATE            HIGH // 高电平，低电平反转（开启=0V，关闭=Vcc通常3.3V）。                     调整项

#define FEATURE5_PURPOSE              OFF // 关闭，开关、瞬时开关、模拟输出、除雾加热器、间隔计。                   可选项
#define FEATURE5_NAME          "FEATURE5" // 功能名称                                                             调整项
#define FEATURE5_TEMP                 OFF // 关闭，热敏电阻 或 DS18B20 序列号。除雾加热器温度传感器。              调整项
#define FEATURE5_PIN                  OFF // 关闭，辅助引脚 或 引脚编号。                                         调整项
#define FEATURE5_VALUE_DEFAULT        OFF // 关闭，开启/0~255（模拟输出）。                                       调整项
#define FEATURE5_VALUE_MEMORY         OFF // 关闭，开启后断电记忆状态。                                           调整项
#define FEATURE5_ON_STATE            HIGH // 高电平，低电平反转（开启=0V，关闭=Vcc通常3.3V）。                     调整项

#define FEATURE6_PURPOSE              OFF // 关闭，开关、瞬时开关、模拟输出、除雾加热器、间隔计。                   可选项
#define FEATURE6_NAME          "FEATURE6" // 功能名称                                                             调整项
#define FEATURE6_TEMP                 OFF // 关闭，热敏电阻 或 DS18B20 序列号。除雾加热器温度传感器。              调整项
#define FEATURE6_PIN                  OFF // 关闭，辅助引脚 或 引脚编号。                                         调整项
#define FEATURE6_VALUE_DEFAULT        OFF // 关闭，开启/0~255（模拟输出）。                                       调整项
#define FEATURE6_VALUE_MEMORY         OFF // 关闭，开启后断电记忆状态。                                           调整项
#define FEATURE6_ON_STATE            HIGH // 高电平，低电平反转（开启=0V，关闭=Vcc通常3.3V）。                     调整项

#define FEATURE7_PURPOSE              OFF // 关闭，开关、瞬时开关、模拟输出、除雾加热器、间隔计。                   可选项
#define FEATURE7_NAME          "FEATURE7" // 功能名称                                                             调整项
#define FEATURE7_TEMP                 OFF // 关闭，热敏电阻 或 DS18B20 序列号。除雾加热器温度传感器。              调整项
#define FEATURE7_PIN                  OFF // 关闭，辅助引脚 或 引脚编号。                                         调整项
#define FEATURE7_VALUE_DEFAULT        OFF // 关闭，开启/0~255（模拟输出）。                                       调整项
#define FEATURE7_VALUE_MEMORY         OFF // 关闭，开启后断电记忆状态。                                           调整项
#define FEATURE7_ON_STATE            HIGH // 高电平，低电平反转（开启=0V，关闭=Vcc通常3.3V）。                     调整项

#define FEATURE8_PURPOSE              OFF // 关闭，开关、瞬时开关、模拟输出、除雾加热器、间隔计。                   可选项
#define FEATURE8_NAME          "FEATURE8" // 功能名称                                                             调整项
#define FEATURE8_TEMP                 OFF // 关闭，热敏电阻 或 DS18B20 序列号。除雾加热器温度传感器。              调整项
#define FEATURE8_PIN                  OFF // 关闭，辅助引脚 或 引脚编号。                                         调整项
#define FEATURE8_VALUE_DEFAULT        OFF // 关闭，开启/0~255（模拟输出）。                                       调整项
#define FEATURE8_VALUE_MEMORY         OFF // 关闭，开启后断电记忆状态。                                           调整项
#define FEATURE8_ON_STATE            HIGH // 高电平，低电平反转（开启=0V，关闭=Vcc通常3.3V）。                     调整项

// ---------------------------------------------------------------------------------------------------------------------------------
#define FileVersionConfig 6
#include "Extended.config.h"