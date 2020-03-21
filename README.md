# Cal-of-Average-sign-entropy
Cal of Average sign entropy in English


##信息论与编码作业

利用计算机编程实现对英文的平均符号熵计算

####使用语言： C++ (python太菜了... 要的比较急)
####计算方式：
####I(a)=-logp(a);H(a)=p(a)*I(a)
####H(a,b)=-p(a,b)*logp(a,b)
###实现方法：
1. 预处理 <---------**FINISHED**
	1. 从before.txt读取文档
	2. 合并段落，替换符号为" "
	2. 大小写处理：统一归类为小写
	3. 符号处理：符号一律变更为" "
	4. 出现多个空格合并为一个空格
	4. 输出字符串，检错 <---会在正式版本删除
2. 计算每个字母出现概率<---------**FINISHED**
3. 计算熵
	1. H(1) <---------**FINISHED**
	2. H(2) <---------**FINISHED**
	3. H(3) 


