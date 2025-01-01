const FILE_PATH: &str = "./q0018.txt";

fn main() {
    let mut triangle: Vec<Vec<u32>> = Vec::new();
    for line in std::fs::read_to_string(FILE_PATH).expect("Error reading input file").lines() {
        triangle.push(line.split_whitespace().map(|substr| substr.parse().unwrap()).collect());
    }

    let mut paths: Vec<Vec<u32>> = Vec::new();
    for mut i in 0..2_usize.pow(triangle.len() as u32) {
        let mut path = vec![triangle[0][0]];

        let mut j = 0;
        for k in 1..triangle.len() {
            if i % 2 == 1 {
                j += 1;
            }
            i /= 2;

            path.push(triangle[k][j]);
        }

        paths.push(path);
    }

    println!("{}",
        paths.into_iter()
            .max_by(|path1, path2| path1.iter().sum::<u32>().cmp(&path2.iter().sum::<u32>()))
            .unwrap()
            .into_iter()
            .sum::<u32>()
    );
}

