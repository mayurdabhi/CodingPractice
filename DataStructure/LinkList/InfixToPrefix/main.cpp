#include <iostream>
#include <stack>
#include <string>

using namespace std;

//True if op2 has higher or same precedence
bool checkPrecedence(char op1, char op2){

    if(op2=='(' || op2==')'){
        return false;
    }
    else if((op1=='*' || op1 == '/') && (op2 == '+' || op2=='-')){
        return false;
    }
    else{
        return true;
    }
}


int ConvertInfixToPrefix(string str){

    stack<char> op;
    stack<string> output;

    for(int i=0;i<str.length();i++){

        cout <<str.at(i)<<endl;
        if(str.at(i)== ' '){
            continue;
        }
        //push Closing Bracket
        if(str.at(i)=='('){
            op.push(str.at(i));
        }
        else if(str.at(i) == ')'){

            while(op.top() !='('){

                string temp1 = output.top() + " ";
                output.pop();
                string temp2 = output.top() + " ";
                output.pop();
                temp2 += temp1;
                temp2 = op.top() + temp2;
                op.pop();
                output.push(temp2);
        //        output.push(op.pop()+temp2 + temp1);
            }
            op.pop();
        }
        else if(str.at(i) >= '0' && str.at(i)<='9'){
            string temp = "";
            //as each number canbe greater then 9
            while(i<str.length() && str.at(i) >= '0' && str.at(i)<='9')
            {
              temp = temp + str.at(i++);
            }
            cout<<temp<<endl;
            output.push(temp);
        }
        else if(str.at(i)=='+' ||str.at(i)=='-' || str.at(i)=='/' || str.at(i)=='*')
        {
            while(!op.empty() && checkPrecedence(str.at(i),op.top())){
                string temp1 = output.top() + " ";
                output.pop();
                string temp2 = output.top() + " ";
                output.pop();
                //when you need to calculate final result, here do calculation.
                temp2 += temp1;
                temp2 = op.top() + temp2;
                op.pop();
                output.push(temp2);
            }
            op.push(str.at(i));
        }
        else{
            //output.push(str.at(i));
        }
    }

    while(!op.empty()){
        string temp1 = output.top() + " ";
        output.pop();
        string temp2 = output.top() + " ";
        output.pop();
        temp2 += temp1;
        temp2 = op.top() + temp2;
        op.pop();
        output.push(temp2);

    }

    cout<<"InfixExpression : "<<str<<endl;
    cout<<"PrefixExpression : "<<output.top()<<endl;
    return 1;
}


int main()
{
   // ConvertInfixToPrefix("10 + 2 * 6");
   // ConvertInfixToPrefix("100 * 2 + 12");
    ConvertInfixToPrefix("100 * ( 2 + 12 )");
    ConvertInfixToPrefix("100 * ( 2 + 12 ) / 14");

    return 0;
}
