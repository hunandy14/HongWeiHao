<h1 id="Hong">Index</h1>
* [洪偉豪(Hong,Wei-Hao)](#Hong)
* [MarkDown for Gitgub](#MarkDown)
* [Python](#Python)
* [OpenCV for python](#OpenCV)
* [Arduino](#Arduino)
* [C語言](#C)
* [網頁設計實務](#html)
* [動態網頁設計實務](#html2)

---

---


<h2 id="MarkDown"> MarkDown for Gitgub </h2>

如本篇介紹
> 正在練習MarkDown語法順手就以此來完成  
> 實際思考應用後也發現，MarkDown相當適合  



<h2 id="Python">Python</h2>
###擔任TA上課內容
* 如何從各個引入檔案，或單一函數  
https://docs.python.org/2/tutorial/modules.html  
* 如何讀寫檔案，以及整理數據，將特定格式(如空白隔開)匯入list  
https://docs.python.org/2/tutorial/inputoutput.html#fancier-output-formatting  
* 簡易的numpy數據處理  
https://docs.scipy.org/doc/numpy-dev/user/quickstart.html  
* 簡易的將數據繪製出圖形  
http://matplotlib.org/users/beginner.html  
* 課堂期間部分程式碼
https://github.com/hunandy14/Uniscript  

###課餘時間作品
* 利用python簡單的寫一個安裝windwos作業系統功能  
https://github.com/hunandy14/Windows_Installer  

>起源於為了將windwos安裝置隨身硬碟，發現windwos本身的安裝程式  
並不支持這樣的操作，上網找了一些指令的方式操作順利成功安裝  
不過安裝過程需打許多指令，指令還要依據盤符做變化，故想簡化流程  

* 利用python抓取推特帳號所有照片  
http://charlottehong.blogspot.tw/2015/12/twitter-picture-download.html

>推特上喜歡的女生想一次抓下所有圖，上網找了一些方法與實踐  
將流程整理好，其中最後一個步驟是取得所有圖片連結與下載  
故使用python來完成，成功抓下大部分圖片  



<h2 id="OpenCV">OpenCV for python</h2>
程式碼連結 https://github.com/hunandy14/OpenCV

###成長過程所練習的程式碼
* Camera_Show.py 看到視訊鏡頭影像
* Color_Capture.py 擷取HSV範圍內影像有紅綠藍範例
* DoubleClick_Auto_Track.py
> 後來我認為顏色範圍不應該慢慢尋找，而是利用滑鼠點擊兩下  
自動變成該範圍，並可即時預覽，同時可透過鍵盤微調  
如此一來就可以很容易的找到自己想要的顏色範圍  

* DoubleClick_Auto_MatchHair.py
> DoubleClick_Auto_Track已經夠完整了，但實際上發現如果要擷取  
頭髮的顏色似乎不太妥當，實際根據HSV模型與HLS模型發現  
兩個的起始顏色是相反的，經過測試這個似乎比較容易吻合頭髮  
實際應用在Drawbot相關訊息(僅第一階二值化段處理)  
> 1. https://www.facebook.com/editpatch/posts/10208222840673870  
> 2. https://www.facebook.com/photo.php?fbid=471642189627772&set=a.106874742771187.6131.100003459855452&type=3  
> 3. https://www.facebook.com/enjoylinux/  
處理能力有限，但勉強還能看畫得出來  
有加入第二代開發團隊，看能不能弄的更完善  
* Get_Img_RGB.py得到該點的RGB值
* Mouse_Drawing.py滑鼠相關操作
* RGB_to_HSV.pyRGB轉HSV值

###釣魚小幫手
程式碼連結 https://github.com/hunandy14/OpenCV/tree/master/FoucsMulti_Dring

>主要功能為判別色塊並替色塊標上代號，代號要一直跟著不能因為旋轉而替換  
當初還不會用git故以檔名標記，回頭來看當初傻傻手動做git  



<h2 id="Arduino">Arduino</h2>
* 以命令控制階層選單

* 藍芽AT命令控制
> 為了方便快速控制，曾經自己寫了一個簡單的批次檔  
> 簡化AT命令的輸入，輸入關鍵字自動完成命令  
> https://gist.github.com/hunandy14/1762cc895eb2f707161a
* 伺服馬達控制
* 步進馬達控制
* LCD控制
* HC-SR04超音波感測距離

* 透過命令控制arduino LED ON off
> https://gist.github.com/hunandy14/5123ae3d5a0c730d5fcb

* 專題釣魚小幫手arduino代碼
> 榮獲103全國微電腦第二名



---------------------------------------------------------------------
<h2 id="C">C語言</h2>

* 單向鏈結排序 - 直接改值  
https://gist.github.com/hunandy14/d55ac9ce14025c28a195  
* 單向鏈結排序 - 改鏈結  
https://gist.github.com/hunandy14/552dcf053285ae5b4a24  

> 這是我寫過最深入的題型[單向鏈結排序]，老師並沒有說明如何達成  
> 自己思考過後發現有兩種寫法，一並繳交  
> 修改方式均以函式操作，主程式內沒有太多多餘的程式  



<h2 id="html">網頁設計實務</h2>

* html語法
* javascript簡易功能

> 記得期末考老師出了一題相當複雜的，要我們在網頁上做一個電梯  
> 那時候還不曉得SCSS與Jqurry傻傻的用javascript一行一行  
> 打出會動可以用的電梯  



<h2 id="html2">動態網頁設計實務</h2>

* XAMPP架站
* XAMPP資料庫
* PHP基本語法(連結資料庫)
* CSS語法
* Javascript(簡易功能)


擷取我認為最好看的部分，留言版花了相當多的時間設計版面  
發想參考自以下各大站，以及平時自己思考所得的想法  

* [Windows10](https://www.microsoft.com/zh-tw/windows/features)
> 以圖形化介面創業成功的的企業  
> 底下的工作列滑鼠移動過去會亮起  

* [Facebook](https://www.facebook.com/)
> 目前台灣最多人使用的，參考如何排版  

* [Twiter](https://twitter.com/)
> 日本最多人使用的，有些不一樣的審美觀  
> 有平面化的設計(顏色)但方塊卻有圓弧  
> 這種新舊觀念混合的設計卻不覺得違和  

* [Hackpad](https://hackpad.com/)
> 標準的平面化設計UI  

![留言板](http://i.imgur.com/a5fpD0j.jpg)





