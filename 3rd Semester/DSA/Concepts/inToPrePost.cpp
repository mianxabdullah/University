#include"TempStack.h"
bool validateExpression(const string &expr)
{
    Stack<char> st(expr.length());
    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.isEmpty()) return false;
            char topChar = st.pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                return false;
            }
        }
    }
    return st.isEmpty();
}
int highprecedence(char op)
{
    if (op == '*' || op == '/')
        return 3;
    else if (op == '+' || op == '-')
        return 2;
    else if (op == '(')
        return 1;
}
bool precedence(char a, char b)
{
    return (highprecedence(a) >= highprecedence(b));
}
string infixToPostfix(string infix)
{
    string postfix = "";
    Stack<char> operators(infix.length());

    for (int i = 0; i < infix.length(); i++)
    {
        char curr = infix[i];
        if ((isalpha(curr)) || (isdigit(curr)))
        {
            postfix += curr;
        }

        else if (curr == '(')
        {
            operators.push(curr);
        }

        else if (curr == ')')
        {
            while (!operators.isEmpty() && operators.StackTop() != '(')
            {
                postfix += operators.pop();
            }
            if (!operators.isEmpty() && operators.StackTop() == '(')
            {
                operators.pop();
            }
        }

        else if (curr == '+' || curr == '-' || curr == '*' || curr == '/')
        {
            while (!operators.isEmpty() && operators.StackTop() != '(' && precedence(operators.StackTop(), curr))
            {
                postfix += operators.pop();
            }
            operators.push(curr);
        }
    }

    while (!operators.isEmpty())
    {
        postfix += operators.pop();
    }

    return postfix;
}
int postfix_evaluation(string postfix)
{
    Stack<char> res(postfix.length());
    for (int i = 0; i < postfix.length() ;  i++)
    {
        char curr = postfix[i];
        if (isdigit(curr))
        {
            res.push(curr);
        }
        else if (curr == '+' || curr == '-' || curr == '*' || curr == '/')
        {
            int operand2= (res.pop()) - '0';
            int operand1 = (res.pop()) - '0';
            int ans = 0;
            if (curr == '+')
                ans = operand1 + operand2;
            else if (curr == '-')
                ans = operand1 - operand2;
            else if (curr == '*')
                ans = operand1 * operand2;
            else if (curr == '/')
                ans = operand1 / operand2;
            res.push(ans+'0');
        }
    }
    return res.pop() - '0';
}
string reverseAndSwapParentheses(string infix)
{
    Stack<char> stack(infix.length());
    string reversed = "";

    for (int i = 0; i < infix.length(); i++)
    {
        stack.push(infix[i]);
    }

    while (!stack.isEmpty())
    {
        reversed += stack.pop();
    }

    for (int i = 0; i < reversed.length(); i++)
    {
        if (reversed[i] == '(')
        {
            reversed[i] = ')';
        }
        else if (reversed[i] == ')')
        {
            reversed[i] = '(';
        }
    }

    return reversed;
}
string infixToPrefix(string infix)
{
    string revInfix = reverseAndSwapParentheses(infix);
    string postfix = infixToPostfix(revInfix);
    string prefix = reverseAndSwapParentheses(postfix);
    return prefix;
}
int prefix_evaluation(string prefix)
{
    Stack<float> res(prefix.length());
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char curr = prefix[i];
        if (isdigit(curr))
        {
            res.push(curr - '0');
        }
        else if (curr == '+' || curr == '-' || curr == '*' || curr == '/')
        {
            float operand1 = (res.pop()) ;
            float operand2 = (res.pop()) ;
            float ans = 0;
            if (curr == '+')
                ans = operand1 + operand2;
            else if (curr == '-')
                ans = operand1 - operand2;
            else if (curr == '*')
                ans = operand1 * operand2;
            else if (curr == '/')
                ans = operand1 / operand2;
            res.push(ans);
        }
    }
    return res.pop();
}
int main()
{
    string infix;
    cout << "Enter infix: ";
    getline(cin, infix);
    cout << endl;

    if (validateExpression(infix))
    {
        string postfix = infixToPostfix(infix);
        string prefix = infixToPrefix(infix);
        int postfixResult = postfix_evaluation(postfix);
        int prefixResult = prefix_evaluation(prefix);

        cout << "Postfix: " << postfix << endl;
        cout << "Prefix: " << prefix << endl;
        cout << "Postfix result: " << postfixResult << endl;
        cout << "Prefix result: " << prefixResult << endl;
    }
    else
    {
        cout << "Invalid expression!" << endl;
    }
}