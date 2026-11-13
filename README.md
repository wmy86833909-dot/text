# text

UE 5.8 小项目：小球在两点之间做往复运动（两端快、中间慢），速度与等待时间可在编辑器里调整。

## 核心代码

- `Source/text/MovingBall.h` — 运动逻辑与可调参数
- `Source/text/MovingBall.cpp` — 曲线计算、往返与等待
- `Source/text/text.Build.cs` — 模块依赖

## 参数

| 参数 | 说明 |
| --- | --- |
| StartPoint / EndPoint | 直线两端 |
| speed | 进度推进速率 |
| WaitTime | 到端点后的停留秒数 |

## 编译

用 UE 5.8 生成工程文件后编译 `textEditor` 目标即可。