#include <iostream>

class Engine
{
    private:
    int board[3][3];

    public:
    //Constructor to initialize board weights to -1
    Engine()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            board[i][j]=-1;
        }
    }
    void draw_board();
    bool validate(int x,int y);
    int trace();
    void play();
    bool draw();


};

//To detect a draw
bool Engine::draw()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==-1)
            {
                return false;
            }
        }
    }
    return true;
}

//Validation function which validates the playes choices
bool Engine::validate(int x,int y)
{
    if((x>2 || x<0) || (y>2 || y<0) || board[x][y]==1 || board[x][y]==2)
    return false;
    else
    return true;
}

//To check the game winning case
int Engine::trace()
{
    
    int sum=0;
    for(int i=0;i<3;i++)
    {
        sum=0;
        for(int j=0;j<3;j++)
        sum+=board[i][j];
        if(sum==3)
        return 1;
        if(sum==6)
        return 2;
    }
    for(int i=0;i<3;i++)
    {
        sum=0;
        for(int j=0;j<3;j++)
        sum+=board[j][i];
        if(sum==3)
        return 1;
        if(sum==6)
        return 2;
    }
    sum=0;
    sum=board[0][0]+board[1][1]+board[2][2];
    if(sum==3)
    return 1;
    if(sum==6)
    return 2;
    sum=0;
    sum=board[0][2]+board[1][1]+board[2][0];
    if(sum==3)
    return 1;
    if(sum==6)
    return 2;

    return 0;
}

//Core function which runs the game
void Engine::play()
{
    int turn=0;
    int x,y;
    while(!draw())
    {
        if(turn%2==0)
        {
            std::cout<<"\nPlayer 1 turn (x):\n";
            std::cout<<"Enter row number:";
            std::cin>>x;
            x=x-1;
            std::cout<<"Enter column number:";
            std::cin>>y;
            y=y-1;
            if(!validate(x,y))
            {
                std::cout<<"Invalied place!\n";
                continue;
            }
            board[x][y]=1;
            draw_board();
            if(trace()==1)
            {
                std::cout<<"\nPlayer 1 wins!\n";
                return;
            }

        }
        else
        {
            std::cout<<"\nPlayer 2 turn(o) :\n";
            std::cout<<"Enter row number:";
            std::cin>>x;
            x=x-1;
            std::cout<<"Enter column number:";
            std::cin>>y;
            y=y-1;
            if(!validate(x,y))
            {
                std::cout<<"Invalied place!\n";
                continue;
            }
            board[x][y]=2;
            draw_board();
            if(trace()==2)
            {
                std::cout<<"\nPlayer 2 wins!\n";
                return;
            }
        }
        turn++;
    }
    std::cout<<"\n==DRAW MATCH==\n";
    return;
}

//FUnction which draws the board
void Engine::draw_board()
{
    std::cout<<"\n==TicTacToe==\n";
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==1)
            {
                std::cout<<" |x| ";
                continue;
            }
            if(board[i][j]==2)
            {
                std::cout<<" |o| ";
                continue;
            }
            else
            std::cout<<" | | ";
        }
        std::cout<<'\n';
    }
}

int main()
{
    Engine e1;
    e1.play();
    return 0;
}