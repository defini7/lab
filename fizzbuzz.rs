fn fizzbuzz(vec: Vec<i64>) {
    for v in vec {
        if v % 3 == 0 {
            println!("fizz");
        } else if v % 5 == 0 {
            println!("buzz");
        } else {
            println!("{}", v);
        }
    }
}

fn main() {
    fizzbuzz((0..20).collect());
}
