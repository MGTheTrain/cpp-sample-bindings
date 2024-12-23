fn main() {
    cxx_build::bridge("src/main.rs")
        .file("src/math-utils.cc")
        .std("c++14")
        .compile("cxxbridge-core");

    println!("cargo:rerun-if-changed=src/main.rs");
    println!("cargo:rerun-if-changed=src/math-utils.cc");
    println!("cargo:rerun-if-changed=include/math-utils.h");
}