#include <iostream>
#include <vector>
#define p1 -1
#define p2 1
 class Ai_Engine
 {
    private:
    int board[3][3];

    public:
    Ai_Engine()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                board[i][j]=0;
            }
        }
    }
    void draw_board();
    bool valied(int x,int y);
    void minmax();
    int win();
    void play();
    bool draw();

 };


int Ai_Engine::win()
{
    int i,j;
    int sum;
    for(i=0;i<3;i++)
    {
        sum=0;
        for(j=0;j<3;j++)
        sum+=board[i][j];
        if(sum==3*p2)
        return p2;
        if(sum==3*p1)
        return p1;
    }
    for(i=0;i<3;i++)
    {
        sum=0;
        for(j=0;j<3;j++)
        sum+=board[j][i];
        if(sum==3*p2)
        return p2;
        if(sum==3*p1)
        return p1;
    }
    sum=0;
    sum=board[0][0]+board[1][1]+board[2][2];
    if(sum==3*p2)
    return p2;
    if(sum==3*p1)
    return p1;
    sum=0;
    sum=board[0][2]+board[1][1]+board[2][0];
    if(sum==3*p2)
    return p2;
    if(sum==3*p1)
    return p1;
    return 0;
}

bool Ai_Engine::draw()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==0)
            return false;
        }
    }
    return true;
}

void Ai_Engine::play()
{
    int x,y;
    int count=0;
    while(!draw())
    {
        if(count%2==0)
        {
            std::cout<<"Players turn:\n";
            std::cout<<"Enter the row name:";
            std::cin>>x;
            x=x-1;
            std::cout<<"Enter the column name:";
            std::cin>>y;
            y=y-1;
            if(valied(x,y))
            {
                board[x][y]=p1;
                draw_board();
                if(win()==p1)
                {
                    std::cout<<"\nPlayer won the game!!\n";
                    return;
                }
            }
            else
            {
                std::cout<<"\nInvalied input!\n";
                continue;
            }
        }
        else
        {
            //computers turn
        }
        count++;
    }
    std::cout<<"\nDraw match!!\n";
}

 void Ai_Engine::draw_board()
 {
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==p1)
            {
                std::cout<<" |x| ";
            }
            else if(board[i][j]==p2)
            {
                std::cout<<" |o| ";
            }
            else
            {
                std::cout<<" | | ";
            }
        }
        std::cout<<"\n";
    }
 }

 bool Ai_Engine::valied(int x,int y)
 {
    if((x<0 || x>2) || (y<0 || y>2))
    return false;
    if(board[x][y]==p1 || board[x][y]==p2)
    return false;
    return true;
 }

 int main()
 {
    Ai_Engine ai;
    ai.play();
 }