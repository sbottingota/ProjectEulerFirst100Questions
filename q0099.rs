const FILE_PATH: &str = "q0099.txt";

fn main() {
    let mut max_line_n = 0_usize;
    let mut max_cmp_val = 0_f64;

    for (i, line) in std::fs::read_to_string(FILE_PATH).unwrap().lines().enumerate() {
        let &[base, exp] = &line.split(',').map(|substr| substr.parse().unwrap()).collect::<Vec<u32>>()[..] else { panic!() };
        
        // Comparing logarithms gives the same result as comparing values, but the values themselves are much smaller.
        // This takes advantage of the fact that log(a^b) = b * log(a) to not have to compute a^b itself.
        let cmp_val = exp as f64 * (base as f64).log2();

        if cmp_val > max_cmp_val {
            max_cmp_val = cmp_val;
            max_line_n = i + 1;
        }
    }

    println!("{}", max_line_n);
}

