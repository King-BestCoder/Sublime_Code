#_*_coding:utf-8_*_
import wx,os

class Dialog1(wx.Dialog):
  def __init__(self,parent):
    self.IDC_BM1=1101
    self.IDC_BM2=1102
    self.IDC_BM3=1103
    
    wx.Dialog.__init__(self, parent, -1, u"复选显示位图选择",pos=(50, 170),size=(300, 180))
    okButton = wx.Button(self, wx.ID_OK, u"确定", pos=(130, 20))
    okButton.SetDefault()
    cancelButton = wx.Button(self, wx.ID_CANCEL, u"取消",pos=(130, 70))
    self.select1 = wx.CheckBox(self, self.IDC_BM1, u"复选位图1", pos=(21, 17))
    self.select2 = wx.CheckBox(self, self.IDC_BM2, u"复选位图2", pos=(21, 47))
    self.select3 = wx.CheckBox(self, self.IDC_BM3, u"复选位图3", pos=(21, 77))
    self.select1.SetValue(self.GetParent().cb1)
    self.select2.SetValue(self.GetParent().cb2)
    self.select3.SetValue(self.GetParent().cb3)
    
    self.Bind(wx.EVT_BUTTON, self.OnOK, okButton)

  def OnOK(self, evt):
    self.GetParent().cb1=self.select1.IsChecked()
    self.GetParent().cb2=self.select2.IsChecked()
    self.GetParent().cb3=self.select3.IsChecked()
    evt.Skip()  # this is neccesary to complete default action of OK button


class Dialog2(wx.Dialog):
  def __init__(self,parent):
    self.IDC_RADIO1=-1
    self.IDC_RADIO2=-1
    self.IDC_RADIO3=-1
    self.radio=[None]*3
    
    wx.Dialog.__init__(self, parent, -1, u"单选显示位图选择",pos=(50, 170),size=(300, 180))
    okButton = wx.Button(self, wx.ID_OK, u"确定", pos=(130, 20))
    okButton.SetDefault()
    cancelButton = wx.Button(self, wx.ID_CANCEL, u"取消",pos=(130, 70))
    self.radio[0] = wx.RadioButton(self, self.IDC_RADIO1, u"单选位图1", pos=(21, 17), style=wx.RB_GROUP)
    self.radio[1] = wx.RadioButton(self, self.IDC_RADIO2, u"单选位图2", pos=(21, 47))
    self.radio[2] = wx.RadioButton(self, self.IDC_RADIO3, u"单选位图3", pos=(21, 77))
    self.radio[self.GetParent().radio].SetValue(True)

    
    self.Bind(wx.EVT_BUTTON, self.OnOK, okButton)
    self.Bind(wx.EVT_BUTTON, self.OnCancel, cancelButton)

  def OnOK(self, evt):
    for i,x in enumerate(self.radio):
      if x.GetValue(): self.GetParent().radio=i; break
    self.GetParent().Refresh()
 
  def OnCancel(self, evt):
    self.GetParent().modalLess=False
    self.Destroy()



class MyFrame(wx.Frame):
  def __init__(self):
    wx.Frame.__init__(self, None, -1, u"第6次上机练习(WX)", size=(800, 500))

#    self.icon1 = wx.Icon(name="icon1.ico", type=wx.BITMAP_TYPE_ICO)
    import tempfile
    tmpfile=tempfile.mktemp()+'.ico'
    import icon1
    icon1.geticon1Image().SaveFile(tmpfile,wx.BITMAP_TYPE_ICO)
    self.icon1 = wx.Icon(name=tmpfile, type=wx.BITMAP_TYPE_ICO)
    self.SetIcon(self.icon1)
#    self.cursor2=wx.Cursor("cur00001.cur",type=wx.BITMAP_TYPE_CUR)
    import cursor1
    tmpfile=tempfile.mktemp()+'.cur'
    cursor1.getcur00001Bitmap().SaveFile(tmpfile,wx.BITMAP_TYPE_BMP)
    self.cursor2 = wx.Cursor(tmpfile,type=wx.BITMAP_TYPE_BMP)

#    self.bmp1=wx.Bitmap("bitmap1.bmp",type=wx.BITMAP_TYPE_BMP)
    import bitmap1
    tmpfile=tempfile.mktemp()+'.bmp'
    bitmap1.getbitmap1Bitmap().SaveFile(tmpfile,wx.BITMAP_TYPE_BMP)
    self.bmp1=wx.Bitmap(tmpfile,type=wx.BITMAP_TYPE_BMP)
    
#    self.bmp2=wx.Bitmap("pig.bmp",type=wx.BITMAP_TYPE_BMP)
    import pig
    pig.getpigBitmap().SaveFile(tmpfile,wx.BITMAP_TYPE_BMP)
    self.bmp2=wx.Bitmap(tmpfile,type=wx.BITMAP_TYPE_BMP)

#    self.bmp3=wx.Bitmap("nuke.bmp",type=wx.BITMAP_TYPE_BMP)
    import nuke
    nuke.getnukeBitmap().SaveFile(tmpfile,wx.BITMAP_TYPE_BMP)
    self.bmp3=wx.Bitmap(tmpfile,type=wx.BITMAP_TYPE_BMP)

    
    self.IDM_DLG1=101
    self.IDM_DLG2=102
    self.IDM_DLG3=103
    self.IDM_CUR1=201
    self.IDM_CUR2=202
    self.IDM_CUR3=203
    self.IDM_LNG1=301
    self.IDM_LNG2=302
    self.IdAbout =401
    self.IDS_STRING00=u"Lab6(WX)"
    self.IDS_STRING10=u"第6次上机练习(WX)"
    self.IDS_STRING01=u"The current cursor is"
    self.IDS_STRING11=u"当前光标是"
    self.IDS_STRING02=u"MY CURSOR"
    self.IDS_STRING12=u"我的光标"

   
    self.Bind(wx.EVT_MENU, self.OnClose, id=wx.ID_EXIT)
    self.Bind(wx.EVT_MENU_RANGE, self.OnDlg,id=self.IDM_DLG1,id2=self.IDM_DLG3)
    self.Bind(wx.EVT_MENU_RANGE, self.OnCur,id=self.IDM_CUR1,id2=self.IDM_CUR3)
    self.Bind(wx.EVT_MENU_RANGE, self.OnLng,id=self.IDM_LNG1,id2=self.IDM_LNG2)
    self.Bind(wx.EVT_MENU, self.OnHelp, id=self.IdAbout)
    self.Bind(wx.EVT_PAINT, self.OnPaint)
    
    self.SetMenuBar(self.CreateCMenu())
    self.cur = self.IDM_CUR1
    self.prompt0=self.IDS_STRING10
    self.prompt1=self.IDS_STRING11
    self.prompt2=self.IDS_STRING12
    self.cursor = wx.StockCursor(wx.CURSOR_ARROW)

    self.modalLess=False
    self.cb1=self.cb2=self.cb3=False
    self.radio=0

    

  def CreateCMenu(self):
    self.menuBar = wx.MenuBar()
    menu = wx.Menu()
    menu.Append(wx.ID_EXIT, u"退出(&x)", "Exit")
    self.menuBar.Append(menu, u"文件(&F)")

    dlgmenu = wx.Menu()
    self.menuBar.Append(dlgmenu, u"对话框(&D)")
    dlgmenu.Append(self.IDM_DLG1, u"模式对话框(&M)\tCtrl+A")
    dlgmenu.Append(self.IDM_DLG2, u"无模式对话框(&L)\tCtrl+B")
    dlgmenu.Append(self.IDM_DLG3, u"文件对话框(&F)\tCtrl+C")

    curmenu = wx.Menu()
    self.menuBar.Append(curmenu, u"光标类型(&C)")
    curmenu.Append(self.IDM_CUR1, u"光标&1(箭头)\tCtrl+1",kind=wx.ITEM_RADIO)
    curmenu.Append(self.IDM_CUR2, u"光标&2(十字)\tCtrl+2",kind=wx.ITEM_RADIO)
    curmenu.Append(self.IDM_CUR3, u"光标&3(自定义)\tCtrl+3",kind=wx.ITEM_RADIO)

    lngmenu = wx.Menu()
    self.menuBar.Append(lngmenu, u"语言(&L)")
    lngmenu.Append(self.IDM_LNG1, u"中文(&C)\tCtrl+Shift+C",kind=wx.ITEM_RADIO)
    lngmenu.Append(self.IDM_LNG2, u"&English\tCtrl+Shift+D",kind=wx.ITEM_RADIO)

    menu = wx.Menu()
    menu.Append(self.IdAbout, u"程序信息(&I)\tF1", "Program Info")
    self.menuBar.Append(menu, u"关于(&A)")

    return self.menuBar

  def CreateEMenu(self):
    self.menuBar = wx.MenuBar()
    menu = wx.Menu()
    menu.Append(wx.ID_EXIT, u"E&xit", "Exit")
    self.menuBar.Append(menu, u"&File")

    dlgmenu = wx.Menu()
    self.menuBar.Append(dlgmenu, u"&Dialog")
    dlgmenu.Append(self.IDM_DLG1, u"&Modal Dialog...\tCtrl+A")
    dlgmenu.Append(self.IDM_DLG2, u"Modal&Less Dialog...\tCtrl+B")
    dlgmenu.Append(self.IDM_DLG3, u"&File Dialog...\tCtrl+C")

    curmenu = wx.Menu()
    self.menuBar.Append(curmenu, u"&Cursor")
    curmenu.Append(self.IDM_CUR1, u"Cursor&1(ARROW)\tCtrl+1",kind=wx.ITEM_RADIO)
    curmenu.Append(self.IDM_CUR2, u"Cursor&2(CROSS)\tCtrl+2",kind=wx.ITEM_RADIO)
    curmenu.Append(self.IDM_CUR3, u"Cursor&3(UserDefined)\tCtrl+3",kind=wx.ITEM_RADIO)

    lngmenu = wx.Menu()
    self.menuBar.Append(lngmenu, u"&Language")
    lngmenu.Append(self.IDM_LNG1, u"中文(&C)\tCtrl+Shift+C",kind=wx.ITEM_RADIO)
    lngmenu.Append(self.IDM_LNG2, u"&English\tCtrl+Shift+D",kind=wx.ITEM_RADIO)

    menu = wx.Menu()
    menu.Append(self.IdAbout, u"Program &Information\tF1", "Program Info")
    self.menuBar.Append(menu, u"&About")
    return self.menuBar


  def OnPaint(self, evt):
    dc=wx.PaintDC(self)
    if self.cur==self.IDM_CUR1:
      dc.DrawText("%s: ARROW"%(self.prompt1),10,10)
    elif self.cur==self.IDM_CUR2:
      dc.DrawText("%s: CROSS"%(self.prompt1),10,10)
    else:
      dc.DrawText("%s: %s"%(self.prompt1,self.prompt2),10,10)
    if self.cb1: self.DrawBMP(dc,self.bmp1,100,50,100,100)
    if self.cb2: self.DrawBMP(dc,self.bmp2,100,150,100,100)
    if self.cb3: self.DrawBMP(dc,self.bmp3,100,250,200,200)
    if   self.radio==0: self.DrawBMP(dc,self.bmp1,400,50,300,300)
    elif self.radio==1: self.DrawBMP(dc,self.bmp2,400,50,300,300)
    else              : self.DrawBMP(dc,self.bmp3,400,50,300,300)

  def DrawBMP(self,dc,bmp,x,y,w,h):
#    dc.DrawBitmap(bmp,x,y)
    dcMem = wx.MemoryDC()
    dcMem.SelectObject(bmp)
    bmpSizeX,bmpSizeY = min(bmp.GetWidth(),w),min(bmp.GetHeight(),h)
    dc.Blit(x, y, bmpSizeX, bmpSizeY, dcMem, 0, 0, wx.COPY)

    
  def OnDlg(self, evt):
    ID=evt.GetId()
    if ID==self.IDM_DLG1:    self.OnDlg1(evt)
    elif ID==self.IDM_DLG2:
      if not self.modalLess: self.OnDlg2(evt)
    else:                    self.OnDlg3(evt)

  def OnDlg1(self, evt):
    dialog = Dialog1(self)
    result = dialog.ShowModal()
    if result == wx.ID_OK:
       self.Refresh()
    dialog.Destroy()

  def OnDlg2(self, evt):
    dialog = Dialog2(self)
    dialog.Show()
    self.modalLess=True

  def OnDlg3(self, evt):
    wildcard ="All Files(*.*)|*.*|"\
              "Python source (*.py)|*.py|"\
              "C++ Files(*.cpp)|*.cpp"
    dialog = wx.FileDialog(self, "Choose a file", os.getcwd(),
                              "", wildcard, wx.OPEN)
    if dialog.ShowModal() == wx.ID_OK:
       self.text = u"所选文件名："+dialog.GetPath()
       wx.MessageBox(self.text,u"文件名", wx.OK , self)

    dialog.Destroy()  

    
  def OnCur(self, evt):
    self.cur=evt.GetId()
    if self.cur==self.IDM_CUR1: self.cursor=wx.StockCursor(wx.CURSOR_ARROW)
    elif self.cur==self.IDM_CUR2: self.cursor=wx.StockCursor(wx.CURSOR_CROSS)
    else: self.cursor=self.cursor2
    self.SetCursor(self.cursor)
    self.Refresh()
  
  def OnLng(self, evt):
    self.lng = evt.GetId()==self.IDM_LNG1
    if self.lng:
      #Chinese
      self.SetMenuBar(self.CreateCMenu())
      self.GetMenuBar().Check(self.IDM_LNG1,True)
      self.prompt0=self.IDS_STRING10
      self.prompt1=self.IDS_STRING11
      self.prompt2=self.IDS_STRING12
    else:
      #English
      self.SetMenuBar(self.CreateEMenu())
      self.GetMenuBar().Check(self.IDM_LNG2,True)
      self.prompt0=self.IDS_STRING00
      self.prompt1=self.IDS_STRING01
      self.prompt2=self.IDS_STRING02
    self.SetTitle(self.prompt0)
    self.SetCursor(self.cursor)
    self.GetMenuBar().Check(self.cur,True)
    self.Refresh()

  def OnHelp(self, evt):
      wx.MessageBox(u"第6次上机练习(WX)\n对话框、光标、字符串、位图\n\n\n\n学号：10152130***\n姓名：******",
           "WXLab6", wx.OK | wx.ICON_INFORMATION, self)
    
  def OnClose(self, evt):
    self.Close()

if __name__ == '__main__':
  import os
#  os.chdir(r"C:\lu\201702\Win15\Lab6")
  app = wx.App()
  frame = MyFrame()
  frame.Show(True)
  app.MainLoop()

 