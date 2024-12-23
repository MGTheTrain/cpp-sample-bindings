namespace Mgtt.CoreWrapper;
class Program
{
    static int Main(string[] args)
    {
        int resultAdd = CoreWrapper.Add(10, 5);
        Console.WriteLine("Addition result: " + resultAdd);

        int resultSubtract = CoreWrapper.Subtract(10, 5);
        Console.WriteLine("Subtraction result: " + resultSubtract);

        int resultMultiply = CoreWrapper.Multiply(10, 5);
        Console.WriteLine("Multiplication result: " + resultMultiply);

        float resultDivide = CoreWrapper.Divide(10.0f, 2.0f);
        Console.WriteLine("Division result: " + resultDivide);

        float radius = 5.0f;

        float area = CoreWrapper.GetCircleArea(radius);
        Console.WriteLine("Circle area: " + area);

        float circumference = CoreWrapper.GetCircleCircumference(radius);
        Console.WriteLine("Circle circumference: " + circumference);

        return 0;
    }
}