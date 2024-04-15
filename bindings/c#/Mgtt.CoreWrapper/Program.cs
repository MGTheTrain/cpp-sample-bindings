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

using CommandLine;

namespace Mgtt.CoreWrapper;
class Program
{
    static int Main(string[] args)
    {
        Options options = null;
        Parser.Default.ParseArguments<Options>(args)
            .WithParsed(o => options = o);

        if (options == null)
        {
            Console.WriteLine("Usage: dotnet run --coreLibraryPath <coreLibraryPath>");
            return 1;
        }

        CoreWrapper.LibraryPath = options.CoreLibraryPath;

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

public class Options
{
    [Option("coreLibraryPath", Required = true, HelpText = "Path to the core library.")]
    public string CoreLibraryPath { get; set; }
}
