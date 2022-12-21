#include <iostream>
using namespace std;

class matrix
{
    friend istream& operator>>(istream &, matrix );
    friend ostream& operator<<(ostream &out, matrix ob);
    friend void transpose(matrix );
    int **mat, row, col;
    public:
    matrix()
    {
        int i;
        row=2;col=2;
        mat= new int*[row];
        for(i=0;i<row;i++)
        {
            mat[i]=new int[col];
        }
    }
    matrix(int row, int col)
    {
        int i;
        this->row=row;
        this->col=col;
        mat= new int*[row];
        for(i=0;i<row;i++)
        {
            
            mat[i]=new int[col];
        }
    }

    int& operator()(int i, int j) const //can't change mat in this function but outside somewhere else we can
    {
        return mat[i][j];
    }

    matrix operator+(matrix );
    matrix operator*(matrix );
    matrix operator=(const matrix & );
};

matrix matrix::operator+(matrix ob2)
{
    if (this->row==ob2.row && this->col==ob2.col)
    {
        matrix ob3(ob2.row,ob2.col);
        int i,j;
        for(i=0;i<ob2.row;i++)
        {
            for(j=0;j<ob2.col;j++)  ob3(i,j)=(*this)(i,j)+ob2(i,j);
        }
        return ob3;
    }
    else
    {
        matrix ob3;
        return ob3;
    }
}

matrix matrix::operator*(matrix ob2)
{
    if (this->col==ob2.row)
    {
        matrix ob3(this->row, ob2.col);
        int i,j,k;
        for (i=0; i<this->row; i++)
        {
            for (j=0; j<ob2.col; j++)
            {
                ob3(i,j)=0;
                for (k=0; k<ob2.row; k++) ob3(i,j) += (*this)(i,k) * ob2(k,j);
            }
        }
        return ob3;
    }
    else
    {
        matrix ob3;
        return ob3;
    }
}

matrix matrix::operator=(const matrix &ob)
{
    int i,j;
    if(this!=&ob)
    {
        this->row=ob.row;
        this->col=ob.col;
        for(i=0;i<row;i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
        mat= new int*[row];
        for(i=0;i<row;i++)
        {
            mat[i]=new int[col];
        }
        for(i=0;i<ob.row;i++)
        {
            for(j=0;j<ob.col;j++)
            {
                (*this)(i,j)=ob(i,j);
            }
        }
    }
}

istream& operator>>(istream &in, matrix ob)
{
    int i,j;
    for(i=0;i<ob.row;i++)
    {
        for(j=0;j<ob.col;j++)
        {
            int x;
            in>>x;
            ob(i,j)=x;
        }
    }
    cout<<endl;
    return in;
}

ostream& operator<<(ostream &out, matrix ob)
{
    int i,j;
    for(i=0;i<ob.row;i++)
    {
        for(j=0;j<ob.col;j++)
        {
            out<<ob(i,j)<<"\t";
        }
        out<<endl;
    }
    out<<endl;
    return out;
}

void transpose(matrix ob) //Square matrix transpose only
{
    int i,j,tmp;
    for (i=0; i<ob.row; i++)
    {
        for (j=1; j<ob.col; j++)
        {
            tmp=ob(i,j);
            ob(i,j)=ob(j,i);
            ob(j,i)=tmp;
        }
    }
}

int main()
{
    matrix m1(3,3),m2(3,3),m3,m4;
    cout<<"Enter the numbers for matrix 1:"<<endl;
    cin>>m1;
    cout<<"Enter the numbers for matrix 2:"<<endl;
    cin>>m2;
    m3=m1+m2;
    m4=m1*m2;
    cout<<m1<<m2<<m3<<m4;
    transpose(m1);
    transpose(m2);
    cout<<m1<<m2; 
}