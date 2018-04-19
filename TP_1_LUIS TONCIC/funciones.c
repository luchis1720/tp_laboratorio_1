float suma (float op1,float op2)
{
    float ans;
    ans = op1 + op2;
    return ans;
}
float resta (float op1,float op2)
{
    float ans;
    ans = op1 - op2;
    return ans;
}
float multiplicacion (float op1,float op2)
{
    float ans;
    ans = op1 * op2;
    return ans;
}
double division (float op1,float op2)
{
    if (op2 != 0)
    {
        double ans;
        ans = (op1 + 0.0) / op2;
        return ans;
    }
    else
    {
        return 0.0;
    }
}
long double factorial(float op1)
{

    if (op1>0)
    {
        long double ans = 1.0;
        float fact;
        for (fact = op1; fact > 1; fact--)
        {
            ans = ans * fact;
        }
        return ans;
    }
    else
    {
        return 0;
    }
}
