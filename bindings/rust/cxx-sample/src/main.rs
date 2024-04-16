use cxx::ExternType;

#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("cxx-sample/include/math-utils.h");
        fn add(a: i32, b: i32) -> i32;
        fn subtract(a: i32, b: i32) -> i32;
        fn multiply(a: i32, b: i32) -> i32;
        fn divide(a: f32, b: f32) -> f32;

        fn getCircleArea(radius: f32) -> f32;
        fn getCircleCircumference(radius: f32) -> f32;
    }
}

fn main() {
    let a = 10;
    let b = 5;
    let result_add: i32;
    let result_subtract: i32;
    let result_multiply: i32;
    let result_divide: f32;

    unsafe {
        result_add = ffi::add(a, b);
        result_subtract = ffi::subtract(a, b);
        result_multiply = ffi::multiply(a, b);
        result_divide = ffi::divide(a as f32, b as f32);
    }

    println!("{} + {} = {}", a, b, result_add);
    println!("{} - {} = {}", a, b, result_subtract);
    println!("{} * {} = {}", a, b, result_multiply);
    println!("{} / {} = {}", a, b, result_divide);

    let radius = 5.0;
    let circle_area: f32;
    let circle_circumference: f32;

    unsafe {
        circle_area = ffi::getCircleArea(radius);
        circle_circumference = ffi::getCircleCircumference(radius);
    }

    println!("Area of circle with radius {}: {}", radius, circle_area);
    println!("Circumference of circle with radius {}: {}", radius, circle_circumference);
}