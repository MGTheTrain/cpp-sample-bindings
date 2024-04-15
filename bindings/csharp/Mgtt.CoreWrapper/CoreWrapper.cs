// The MIT License
//
// Copyright (c) 2024 MGTheTrain
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
