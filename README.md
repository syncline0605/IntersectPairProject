### 软件工程结对项目

作业地址：[https://edu.cnblogs.com/campus/buaa/BUAA_SE_2020_LJ/homework/10466](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2020_LJ/homework/10466)

博客地址：[https://www.cnblogs.com/syncline/p/12559007.html](https://www.cnblogs.com/syncline/p/12559007.html)

#### 命令行可执行文件

- 位置：bin/intersect.exe
- 源代码：src/

对给定的N个几何对象，询问平面中有多少个点在**至少2个**给定的集合对象上。

支持的几何对象为：直线、射线、线段、圆。

##### 输入文件格式

- 第 1 行：一个自然数 N >= 1，表示输入的几何对象的数目。**注**：具体的 N 的限制参见评分规则。
- 第 2 行至第 N + 1 行：每行描述一个几何对象。具体格式如下： 
  - 直线：`L <x1> <y1> <x2> <y2>`，表示通过点 (x1, y1) 和 (x2, y2) 的直线。输入保证给定两点不重合。
  - 射线（新增需求）：`R <x1> <y1> <x2> <y2>`，表示起点为 (x1, y1)，且通过点 (x2, y2) 的射线。输入保证给定两点不重合。
  - 线段（新增需求）：`S <x1> <y1> <x2> <y2>`，表示以 (x1, y1) 和 (x2, y2) 为端点的线段。输入保证给定两点不重合。
  - 圆（附加题）：`C <x> <y> <r>`，表示以点 (x, y) 为中心，半径为 r 的圆。输入保证半径 r > 0。

##### 命令行参数

| 参数                       | 参数意义                                         | 用法示例                                   |
| -------------------------- | ------------------------------------------------ | ------------------------------------------ |
| `-i <path to input file>`  | 带一个参数，表示输入文件的路径（绝对或相对路径） | `intersect.exe -i input.txt -o output.txt` |
| `-o <path to output file>` | 带一个参数，表示输出文件的路径（绝对或相对路径） | `intersect.exe -i input.txt -o output.txt` |



#### GUI可执行文件

- 位置：GUI/GUI.exe
- 源代码：UIsrc/

- 运行方法：运行GUI/GUI.exe
- 具体使用方法：见博客 [https://www.cnblogs.com/syncline/p/12559007.html](https://www.cnblogs.com/syncline/p/12559007.html)