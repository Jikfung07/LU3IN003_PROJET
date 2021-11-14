<center><font size=6><b>PROJET LU3IN003</b></font></center>



<font size=4><b>1. 介绍(Introduction)</b></font>

​		<font size=2>在一个烹饪论坛上，我们可以看到以下问题：
“我刚刚制作了大量的果酱，我准备了各种大小的罐子，准备把它们分装倒进去。我有各种大小的罐子，准备把它倒进去。但我在想一个问题：我最少需要多少个罐子，把他们全部装满，来保存我的果酱？"</font>

​		<font size=2>本项目的目的是要回答这个问题。当分装果酱时，它们仍然仍然是液体，必须迅速倒入像下面图片中的罐子中。重要的是要完全填满每个罐子，即恰好符合其容量。否则，罐子里的空气会限制其储存时间。但也有不同容量的罐子!
你的目标将是设计适应不同容量罐子的算法：鉴于
考虑到罐子的容量和果酱的量，目标是使用尽可能少的罐子。</font>



<b>问题转化(Définition du problème)：</b>

​		<font size=2>记 <b>S</b> (单位dg，分克) 为我们应倒入空罐子的果酱的量</font>

​		<font size=2>我们将这些多种容量的罐子分为 <b>k</b> 类不同的罐子，每一类罐子对应一种不同的容量。我们称 <b><i>容量系统 (systéme de capacités)</i></b> 为所有容量的集合。用大小为 <b>k</b> 的数组 <b>V</b> 通过 (容量的) 升序来记录这  <b>k</b> 种容量：</font>

<center>V[1]&ltV[2]&lt ... ... &ltV[k]</center>

​		<font size=2>容量 <b>V[i]</b> 表示每种罐子可以装的量(dg, 分克)。例如， <b>k = 8</b>, <b>V = [1, 2, 5, 10, 20, 50, 100, 200]</b> </font>

<font size=2>我们作出以下假设：</font>

​				<font size=1>-含量的数量S是一个整数的分克，例如 S=200分克（2公斤）。</font>

​				<font size=1>-最小的一个罐子的容量为1分克，即V[1]=1。</font>

​				<font size=1>-每种容量的罐子都有非常大的数量（因此假设是无限的）。</font>

​		<font size=2>为了符合第一个假设，有必要有点贪心。这三个假设让我们可以说，我们的问题总是有解决方案的：即，只填满那些1分克(10克)的罐子。</font>

​		<font size=2>我们的目标是尽可能少地装满罐子，<b>要知道每个罐子必须准确地装到其最大容量。</b>因此，鉴于:</font>

​				<font size=1>一个容量为 <b><i>k</i></b> 的系统 (système de <b><i>k</i></b> capacités) $V \in \mathbb{N}, i \in \{1, ... ,k\}, V[1] = 1$</font>

​				<font size=1>和一个量为 $S \in \mathbb{N}$ 分克的果酱</font>

​		<font size=2>目的是确定最小的罐子数量，使得它们的容量之和恰好等于 <b>S</b>。我们力图返回一对 <b>(n,A)</b>, 其中 <b>n</b> 是使用的罐子数量，<b>A</b> 是一个大小为 <i>k</i> 的数组，<b>A[i]</b> 表示装满的容量为 <b>V[i]</b> 的罐子数量，并记 $n=\sum_{i=1}^k A[i]$</font>

​		<font size=2>对于容量数组 <b>V = [1, 2, 5, 10, 20, 50, 100, 200]</b> 和一个质量为 <b>S = 748 dg</b>的果酱，例如，必须填满最少9个罐子：3个200 dg，1个100 dg，2个20 dg，1个5 dg，1个2dg 和 1个1 dg。通过一个算法得到的结果将会是一对 <b>(9, [1,1,1,0,2,1,3])</b></font>



<b>项目的目的(Objectifs du projet):</b>

<font size=2>该项目旨在分析和实现解决上述问题的几种算法。该工作分为<b>理论部分</b>和<b>实验部分</b>。<b>理论部分</b>将问题形式化，并允许建立和分析几种算法及其各自的复杂度。<b>实验部分</b>涉及到这些算法的实施和对其各自复杂度的实验验证。</font>



<font size=4><b>2. 理论部分(Partie théorique)</b></font>

<font size=2>在这一部分，我们将研究三种解决选择罐子问题的算法。</font>

<font size=3><b>2.1 算法一(Algorithme I)</b></font>

<font size=2>我们记 <b><i>m(S)</i></b> 为对于果酱 <b>S dg</b> 和容量数组 <b>V</b> 的所需最小罐数。我们将一系列的中间问题定义如下：给定一个整数 <b>S</b> 和一个整数 $i \in \{1, ... , k\}$，记 <b>m(s,i)</b> 为 对于 <b>S dg</b> 的果酱只在容量系统 <b>V[1], V[2], ..., V[i]</b>中选择罐子时所需罐子的最小数量 (吐了。。法语版贼你妈绕口)</font>

<font size=2>为了初始化这个递归，我们设：</font>

​	<font size=1>- <i>m(0,i)</i> = 0, $\forall i \in \{1, ... ,k\}$ : 有可能存在0 dg的果酱和0个罐子</font>

​	<font size=1>-<i>m(s,0)</i> = $+\infty$, $\forall s \geq 1$ : 不可能存在 $s \ge 1$ 但一个罐子都不需要的情况</font>

​	<font size=1>-<i>m(s,i)</i> = $+\infty$, $\forall i \in \{1, ... ,k \}$, $\forall s < 0$ : 不可能存在 $s$ 总量为负数的情况</font>

<font size=2><b>Q1.</b></font>

<font size=2>a) 根据在前面定义的 <i>m(s,i)</i> 的值求出 <i>m(S)</i> 的值</font>

<font size=2>b) 对于$i \in \{1, ... , k \}$, 证明下面的递推关系</font>
$$
m(s,i) = \left\{\begin{array}{rcl}
0 & si\ s = 0 \\
min\{m(s,i-1),m(s-V[i],i)+1) \} & sinon
\end{array}\right.
$$


<font size=2><b>Q2.</b></font>

<font size = 2>通过上一小题的递推关系得到的 <i>m(s,i)</i> 的值，允许我们找出 <b>m(S)</b>。(用伪代码) 写出一个基于这种递推关系的算法，并计算出 <b>m(S)</b> 的值，不要忘记指出算法中的起始调用(l'appel initial)。这种算法将<b>不</b>使用辅助数组去保存已经计算出来的值。</font>



<font size=2><b>Q3.</b></font>

<font size = 2>对于S = 5，k = 2, V[1] = 1 和 V[2] = 2，展现出你的算法的递归树 (l'arbre des appels récursifs de votre algorithme)。</font>



<font size=2><b>Q4.</b></font>

<font size = 2>在前一题的树中，<i>m(1,1)</i> 被计算了多少次？更简单地来说，如果k = 2, 有V[1] = 1 和 V[2] = 2时，用S来表示 <i>m(1,1,)</i> 会被计算多少次？(假设S是偶数)</font>

