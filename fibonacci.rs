fn fibonacci(last: i32) -> Vec<i32> {
    let mut fib = Vec::new();
    fib.push(1);
    fib.push(1);

    for _ in 0..last - 2 {
        fib.push(fib[fib.len() - 1] + fib[fib.len() - 2]);
    }

    return fib;
}

fn main() {
    let fib = fibonacci(5);
    for f in fib {
        println!("{}", f);
    }
}
