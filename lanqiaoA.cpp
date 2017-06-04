#_*_coding:utf-8_*_

import wx
class MyFrame(wx.Frame):
  def __init__(self):
    wx.Frame.__init__(self, None, -1, u"第4次上机练习(WX)", size=(800, 500))
    str[3]={'IDC_ARROW','IDC_CROSS','自定义光标'}
#    self.icon1 = wx.Icon(name="icon1.ico", type=wx.BITMAP_TYPE_ICO)
    import tempfile
    tmpfile=tempfile.mktemp()+'.ico'
    import icon1
    icon1.geticon1Image().SaveFile(tmpfile,wx.BITMAP_TYPE_ICO)
    self.icon1 = wx.Icon(name=tmpfile, type=wx.BITMAP_TYPE_ICO)
    import icon2
    icon2.geticon2Image().SaveFile(tmpfile,wx.BITMAP_TYPE_ICO)
    self.icon2 = wx.Icon(name=tmpfile, type=wx.BITMAP_TYPE_ICO)
    import icon3
    icon3.geticon3Image().SaveFile(tmpfile,wx.BITMAP_TYPE_ICO)
    self.icon3 = wx.Icon(name=tmpfile, type=wx.BITMAP_TYPE_ICO)

#    self.icon2 = wx.Icon(name="icon2.ico", type=wx.BITMAP_TYPE_ICO)
#    self.icon3 = wx.Icon(name="icon3.ico", type=wx.BITMAP_TYPE_ICO)

    self.SetIcon(self.icon1)

    self.menuBar = wx.MenuBar()
    menu = wx.Menu()
    menu.Append(wx.ID_EXIT, "E&xit\tCtrl+Shift+Delete", "Exit")
    self.Bind(wx.EVT_MENU, self.OnClose, id=wx.ID_EXIT)
    self.menuBar.Append(menu, "&File")
    #iconmenu
    iconmenu = wx.Menu()
    self.IDM_ICON1,self.IDM_ICON2,self.IDM_ICON3 = 201,202,203
    self.menuBar.Append(iconmenu, u"图标(&I)")
    iconmenu.Append(self.IDM_ICON1, u"图标&1\tCtrl+1",kind=wx.ITEM_RADIO)
    iconmenu.Append(self.IDM_ICON2, u"图标&2\tCtrl+2",kind=wx.ITEM_RADIO)
    iconmenu.Append(self.IDM_ICON3, u"图标&3\tCtrl+3",kind=wx.ITEM_RADIO)
    self.Bind(wx.EVT_MENU_RANGE, self.OnIcon,id=self.IDM_ICON1,id2=self.IDM_ICON3)
    self.menuBar.Check(self.IDM_ICON1,True)	
    self.icon_type=1

    #dispmenu
    self.dispmenu = wx.Menu()
    self.IDM_DISP1,self.IDM_DISP2,self.IDM_DISP3,self.IDM_DISP4 = 301,302,303,304
    self.menuBar.Append(self.dispmenu, u"显示(&D)")
    self.dispmenu.Append(self.IDM_DISP1, u"显示&1\tCtrl+Shift+1",kind=wx.ITEM_CHECK)
    self.dispmenu.Append(self.IDM_DISP2, u"显示&2\tCtrl+Shift+2",kind=wx.ITEM_CHECK)
    self.dispmenu.Append(self.IDM_DISP3, u"显示&3\tCtrl+Shift+3",kind=wx.ITEM_CHECK)
    self.dispmenu.Append(self.IDM_DISP4, u"显示&4\tCtrl+Shift+4",kind=wx.ITEM_CHECK)
    self.Bind(wx.EVT_MENU_RANGE, self.OnDisp,id=self.IDM_DISP1,id2=self.IDM_DISP4)
    self.disp1=self.disp2=self.disp3=self.disp4=False
	
    menu = wx.Menu()
    IdAbout = menu.Append(-1, u"程序信息(&I)\tF1", "Program Info")
    self.Bind(wx.EVT_MENU, self.OnHelp, IdAbout)
    self.menuBar.Append(menu, u"关于(&A)")
    self.SetMenuBar(self.menuBar)

    self.Bind(wx.EVT_PAINT, self.OnPaint)

  def OnPaint(self, evt):
    dc=wx.PaintDC(self)
    dc.DrawText(u"当前使用的图标是: 图标%d"%self.icon_type,100,50)
    if self.disp1: dc.DrawText(u"显示1",200,200)
    if self.disp2: dc.DrawText(u"显示2",200,300)
    if self.disp3: dc.DrawText(u"显示3",300,200)
    if self.disp4: dc.DrawText(u"显示4",300,300)


  def OnHelp(self, evt):
      wx.MessageBox(u"第4次上机练习(WX)\n图标、菜单、加速键、消息框\n\n学号：10152130***\n姓名：******",
           "Lab4(WX)", wx.OK | wx.ICON_INFORMATION, self)
	
  def OnClose(self, evt):
    self.Close()

  def OnIcon(self, evt):
    ID=evt.GetId()
    if self.icon_type==1 and ID==self.IDM_ICON1 or \
       self.icon_type==2 and ID==self.IDM_ICON2 or \
       self.icon_type==3 and ID==self.IDM_ICON3 : return 
    if wx.MessageBox(u"确定要修改吗？",u"Confirmation",wx.ICON_QUESTION | wx.YES_NO) == wx.NO: 
      if self.icon_type==1: self.menuBar.Check(self.IDM_ICON1,True)
      if self.icon_type==2: self.menuBar.Check(self.IDM_ICON2,True)
      if self.icon_type==3: self.menuBar.Check(self.IDM_ICON3,True)
      return
    if ID==self.IDM_ICON3:
      self.SetIcon(self.icon3)
      self.icon_type=3
      self.GetMenuBar().EnableTop(2, False)
      self.GetMenuBar().Enable(self.IDM_DISP1, False)
      self.GetMenuBar().Enable(self.IDM_DISP2, False)
      self.GetMenuBar().Enable(self.IDM_DISP3, False)
      self.GetMenuBar().Enable(self.IDM_DISP4, False)
    else:
      self.GetMenuBar().EnableTop(2, True)
      self.GetMenuBar().Enable(self.IDM_DISP1, True)
      self.GetMenuBar().Enable(self.IDM_DISP2, True)
      self.GetMenuBar().Enable(self.IDM_DISP3, True)
      self.GetMenuBar().Enable(self.IDM_DISP4, True)
      if ID==self.IDM_ICON1:
        self.SetIcon(self.icon1)
        self.icon_type=1
      elif ID==self.IDM_ICON2:
        self.SetIcon(self.icon2)
        self.icon_type=2
    self.Refresh()

  def OnDisp(self, evt):
    ID=evt.GetId()
    checked = evt.IsChecked()
    if ID==self.IDM_DISP1: self.disp1=checked
    elif ID==self.IDM_DISP2:self.disp2=checked
    elif ID==self.IDM_DISP3:self.disp3=checked
    elif ID==self.IDM_DISP4:self.disp4=checked
    self.Refresh()

if __name__ == '__main__':
  app = wx.App()
  frame = MyFrame()
  frame.Show(True)
  app.MainLoop()
