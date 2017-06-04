//游戏的主过程
void playGame()
{
    while (win == 0)
    {
        if (whoseTurn == 0)
        {
            bool inputCorrect;
            char p_i; char p_j;
            do
            {
                cout << "请输入落子的坐标：(X,Y)" << endl;
                cout << "输入q退出游戏" << endl;
                cin >> p_i;
                if (p_i == 'q' || p_i == 'Q')
                {
                    cout << "退出游戏" << endl;
                    exit(0);
                }
                cin >> p_j;
                if (p_j == 'q' || p_j == 'Q')
                {
                    cout << "退出游戏" << endl;
                    exit(0);
                }

                inputCorrect = addToMap(currentMap, p_i, p_j, whoseTurn);
            }while (!inputCorrect);
            drawMap(currentMap, p_i, p_j);
            hand++;
            int pos_x, pos_y;
            pos_x = (('0' < p_i) && ('9' >= p_i)) ? p_i - 48 : p_i - 'A' + 10;
            pos_y = (('0' < p_j) && ('9' >= p_j)) ? p_j - 48 : p_j - 'A' + 10;
            if (LinkF5(pos_x - 1, pos_y - 1, currentMap))
            {
                win = 1;
                break;
            }
            whoseTurn = 1;
        }
        else
        {
            cout << "计算机在思考。。。" << endl;
            cut = 0;
            computer_think();
            cout << "cut = " << cut << endl;
            hand++;
            whoseTurn = 0;
        }
        if (hand > 100)
            win = 3;
    }
    switch (win)
    {
        case 1:cout << "人类赢了!" << endl; break;
        case 2:cout << "AI赢了!" << endl; break;
        case 3:cout << "百手和棋!" << endl; break;
    }
    char c;
    cin >> c;
}