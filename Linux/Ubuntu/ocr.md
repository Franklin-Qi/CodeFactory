# OCR 技术
OCR英文全称是Optical Character Recognition，中文叫做光学字符识别。
它是利用光学技术和计算机技术把印在或写在纸上的文字读取出来，并转换成一种计算机能够接受、人又可以理解的格式。
现在这技术已经比较成熟。实际应用：比如一个手机APP就能帮忙扫描名片、身份证，并识别出里面的信息；
汽车进入停车场、收费站都不需要人工登记了，都是用车牌识别技术；
我们看书时看到不懂的题，拿个手机一扫，APP就能在网上帮你找到这题的答案。

## OCR 分类
手写体和印刷体识别

## OCR 流程
假如输入系统的图像是一页文本，那么识别时的第一件事情是判断页面上的文本朝向，
因为我们得到的这页文档往往都不是很完美的，很可能带有倾斜或者污渍，
那么我们要做的第一件事就是进行图像预处理，做角度矫正和去噪。然后我们要对文档版面进行分析，
进每一行进行行分割，把每一行的文字切割下来，最后再对每一行文本进行列分割，切割出每个字符，
将该字符送入训练好的OCR识别模型进行字符识别，得到结果。但是模型识别结果往往是不太准确的，
我们需要对其进行识别结果的矫正和优化，比如我们可以设计一个语法检测器，
去检测字符的组合逻辑是否合理。比如，考虑单词Because，我们设计的识别模型把它识别为8ecause，
那么我们就可以用语法检测器去纠正这种拼写错误，并用B代替8并完成识别矫正。
这样子，整个OCR流程就走完了。从大的模块总结而言，一套OCR流程可以分为：

> 版面分析 -> 预处理 -> 行列分割 -> 字符识别 -> 后处理识别矫正


## 识别方法
现在我们只想单纯地想对字符进行识别，可以采取的策略：

> 1. 使用谷歌开源OCR引擎Tesseract。英文和数字精确，但中文不完善，需要自己微调。
> 2. 使用大公司的OCR开放平台（比如百度），使用他们的字符识别API。大量调用收费，不适合商用;
> 3. 传统方法做字符的特征提取，输入分类器，得出OCR模型;
> 4. 暴力的字符模板匹配法，简单场景(识别车牌号);
> 5. 大杀器：基于深度学习下的卷积神经网络CNN(Convolutional neural networks)字符识别。需要大量训练数据和时间


## 参考
[OCR博客](https://blog.csdn.net/qq_34886403/article/details/86770151)
