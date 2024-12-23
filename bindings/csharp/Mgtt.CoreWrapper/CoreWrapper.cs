using System.Runtime.InteropServices;

namespace Mgtt.CoreWrapper;
public class CoreWrapper
{
    [DllImport("core_wrapper", EntryPoint = "add")]
    public static extern int Add(int a, int b);

    [DllImport("core_wrapper", EntryPoint = "subtract")]
    public static extern int Subtract(int a, int b);

    [DllImport("core_wrapper", EntryPoint = "multiply")]
    public static extern int Multiply(int a, int b);

    [DllImport("core_wrapper", EntryPoint = "divide")]
    public static extern float Divide(float a, float b);

    [DllImport("core_wrapper", EntryPoint = "getCircleArea")]
    public static extern float GetCircleArea(float radius);

    [DllImport("core_wrapper", EntryPoint = "getCircleCircumference")]
    public static extern float GetCircleCircumference(float radius);
}
