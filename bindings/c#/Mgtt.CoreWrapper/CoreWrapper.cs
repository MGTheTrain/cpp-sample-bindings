using System;
using System.Runtime.InteropServices;

namespace Mgtt.CoreWrapper
{
    public class CoreWrapper
    {
        public static string _libraryPath {get; set;}

        [DllImport("{LibraryPath}", EntryPoint = "add")]
        public static extern int Add(int a, int b);

        [DllImport("{LibraryPath}", EntryPoint = "subtract")]
        public static extern int Subtract(int a, int b);

        [DllImport("{LibraryPath}", EntryPoint = "multiply")]
        public static extern int Multiply(int a, int b);

        [DllImport("{LibraryPath}", EntryPoint = "divide")]
        public static extern float Divide(float a, float b);

        [DllImport("{LibraryPath}", EntryPoint = "getCircleArea")]
        public static extern float GetCircleArea(float radius);

        [DllImport("{LibraryPath}", EntryPoint = "getCircleCircumference")]
        public static extern float GetCircleCircumference(float radius);
    }
}
