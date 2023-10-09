//starting source code on this page will probably finish around Tuesday

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

struct matrix {
    double x;
    double y;
             };

//Prototypes
void intro();
void info();
void get_matrix(string&, matrix&);
void menu(string&,string&,string&,string&,string&,string&, string&);
void calc_sum(matrix&, matrix&, matrix&);
void calc_diff(matrix&, matrix&, matrix&);
void Print_matrix(fstream&, string&, matrix&);
void Scalar_multi(matrix&, int, matrix&);
int Scalar_product(matrix&,matrix&);
void Print_matrix2(fstream&, string&, int&);
double inverse(matrix&);
void Print_matrix3(fstream&, string&, double&);

//main where functions get called
int main()
{
    fstream outfile;
    matrix m1, m2, differ, sum, s_mult1, s_mult2;
    string name1, name2, cal_s,dif_s,scal_m_s,scal_m2_s,scal_p_s, inv_s, inv_2;
    int count=0, choice, prod;
    double inv, inv2;
    
    outfile.open ("matrix.txt", ios::app);
    outfile.close();
    
    intro();
    get_matrix(name1, m1);
    cout<<endl;
    info();
    cin.clear();
    get_matrix(name2, m2);
    cout<<endl;
    Print_matrix(outfile,name1,m1);
    cout<<endl;
    Print_matrix(outfile,name2,m2);
    
    
    while(count<1)
    {
        menu(cal_s,dif_s,scal_m_s,scal_m2_s,scal_p_s, inv_s, inv_2);
        cin>>choice;
        switch(choice)
        {
            case 1: calc_sum(m1,m2,sum);
                    Print_matrix(outfile,cal_s , sum);
                 break;
                
            case 2: calc_diff(m1, m2, differ) ;
                    Print_matrix(outfile,dif_s,differ);
                 break;
                
            case 3: Scalar_multi(m1, 4.5 ,s_mult1) ;
                    Print_matrix(outfile,scal_m_s,s_mult1);
                 break;
                
            case 4: Scalar_multi(m2, 4.5 ,s_mult2) ;
                    Print_matrix(outfile,scal_m2_s,s_mult2);
                 break;
                
            case 5:prod = Scalar_product(m1, m2) ;
                    Print_matrix2(outfile,scal_p_s,prod);
                 break;
                
            case 6: inv = inverse(m1);
                    Print_matrix3(outfile, inv_s,inv);
                 break;
                
            case 7:inv2 = inverse(m2);
                    Print_matrix3(outfile, inv_2,inv2);
                 break;
                
            case 8:count= count+1;
                break;
            
            default:cout<<"Please enter a valid selection, try again...\n\n\n" ;
        }
    }
    return 0;
    
}
// Begining of functions being called from main

void intro()
{
    cout<<" Welcome this program will calculate 2 matrixes, please start by entering the first name and matrix."<<endl;
}

void info()
{
    cout<<"\n\n Please enter the 2nd name and matrix now...\n";
    
}

void get_matrix(string &name, matrix &m)
{
    cout<<"\nName: ";
    getline(cin, name);
    cin.clear();
        
    cout<<endl<<"Matrix x: ";
    cin>> m.x;
    cout<<"\nMatrix y: ";
    cin>>m.y;
    cin.ignore();
       
    
}


void menu(string& cal_s,string &dif_s,string &scal_m_s,string &scal_m2_s,string &scal_p_s,string &inv_s,string  &inv_2)
{
    cout<<"\n\nPlease choose an option below to calculate or exit the program...";
    cout<<"\n1. Sum\n2. Differance\n3.Scalar multiplication m1\n4.Scalar multiplication m2\n5.Scalar Product\n6.Inverse m1\n7.Inverse m2\n8. Exit\n\n";
    cout<<"choice: ";
    
    cal_s = "\n Sum of Matrix 1 and 2 =";
    dif_s = "\n The Difference of Matrix 1 and 2 =";
    scal_m_s = "\n Scalar multiple of Matrix 1 =";
    scal_m2_s="\n Scalar multiple of Matrix 2 =";
    scal_p_s ="\n Scalar Product of Matrix 1 & 2 =";
    inv_s = "\n Inverse of Matrix 1 =";
    inv_2 = "\n Inverse of Matrix 2 =";
    
}

void calc_sum(matrix &m1, matrix &m2, matrix &sum)
{
    sum.x = (m1.x + m2.y);
    sum.y = (m1.y + m2.x); 
}

void calc_diff(matrix &m1, matrix &m2, matrix &differ)
{
    differ.x= (m1.x - m2.y);
    differ.y= (m1.y - m2.x);
}

void Scalar_multi(matrix &m, int k, matrix &s_mult)
{
    s_mult.x = k*m.x;
    s_mult.y = k*m.y;
}

int Scalar_product(matrix &m1, matrix &m2 )
{
    int prod;
    
    prod = (m1.x*m2.y) + (m1.y*m2.x);
    
    return prod;
}

double inverse ( matrix &m)
{
    double inv;
    int det= (m.x*m.y) - (m.y*m.x);
    inv = (m.y/det) , (-m.x/det);
    
    return inv;
}

void Print_matrix(fstream &outfile, string &statement, matrix &m)
{
    outfile.open ("Matrix.txt", ios::out);
    outfile<<statement<<" "<<m.x<<"  "<<m.y;
    cout<<statement<<" "<<m.x<<"  "<<m.y;
    outfile.close();
}


void Print_matrix2(fstream &outfile, string &statement, int &prod)
{
    outfile.open ("Matrix.txt", ios::out);
    outfile<<statement<<" "<<prod;
    cout<<statement<<" "<<prod;
    outfile.close();
}

void Print_matrix3(fstream &outfile, string &statement, double &inv)
{
    outfile.open ("Matrix.txt", ios::out);
    outfile<<statement<<" "<<inv;
    cout<<statement<<" "<<inv;
    outfile.close();
}








