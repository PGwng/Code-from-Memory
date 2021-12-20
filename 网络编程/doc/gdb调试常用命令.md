gdb调试常用命令

```shell
gdb 可执行程序文件名	//进入gdb调试
b 行号n				//在行号n处添加断点
c					 //（continue）继续运行
r					 //运行
n					 //单步执行
display 变量名		   //将变量的值显示出来（undisplay取消对变量的跟踪）
p 对象名（变量名）		//打印该对象
i breakpoints		 //（information） 查看已设置断点的信息
delete 断点编号		  //删除某个端点（每个断点都有一个编号，可通过info命令查询）
disable/enable 断点编号		//暂时禁用/启用某个断点
b 行号n if 某个条件	 //当满足某个条件时，在第n行处添加断点

//断点是当程序执行到某一代码行时中断，而观察点是当程序访问某个存储单元时中断，如果我们不知道某个存储单元是在哪里被改动的，这时候观察点尤其有用。
watch 变量名			//在该变量处设置观察点
c					  //continue后，程序执行到该变量存储单元，将此存储单元执行前后的值都显示出来

q(quit)				 //退出gdb模式

set args		//设置主程序的参数。例如：./book119 /oracle/c/book1.c /tmp/book1.c
				//设置参数的方法是：
				//gdb book119
				//(gdb) set args /oracle/c/book1.c /tmp/book1.c
s(step)			//执行当前行语句，如果该语句为函数调用，则进入函数执行其中的第一条语句。
				//注意了，如果函数是库函数或第三方提供的函数，用s也是进不去的，因为没有源代码，
				//如果是您自定义的函数，只要有源码就可以进去。
set var name=value	//设置变量的值，假设程序有两个变量：int i; char name[21];
					//set var i=10 把i的值设置为10；
					//set var name="张三" 把name的值设置为"张三"，注意，不是strcpy
```



**gdb调试多进程程序**

调试父进程：

```
set follow-fork-mode parent		//(缺省)
```

调试子进程：

```
set follow-fork-mode child
```

设置调试模式：

```
set detach-on-fork [on|off]		//缺省是on
```

表示调试当前进程的时候，其它的进程继续运行，如果用off，调试当前进程的时候，其他进程被gdb挂起。

查看调试的进程：

```
info inferiors
```

切换当前调试的进程：

```
inferior 进程id
```



**gdb调试多线程程序**

在shell中执行：

查看当前运行的进程：ps aux | grep 进程名

查看当前运行的轻量级进程：ps -aL | grep 进程名

查看主线程和子线程的关系：pstree -p 主线程id

在gdb中执行：

查看线程：

```
info threads
```

切换线程：

```
thread 线程id
```

只运行当前线程：

```
set scheduler-locking on
```

运行全部的线程：

```
set scheduler-locking off
```

指定某线程执行某gdb命令：

```
thread apply 线程id cmd
```

全部的线程执行某gdb命令：

```
thread apply all cmd
```







