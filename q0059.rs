const FILE_PATH: &str = "q0059.txt";
const THE_THRESHOLD: usize = 7;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let input = std::fs::read_to_string(&FILE_PATH)?;
    let cyphertext: Vec<u8> = input
        .split(',')
        .map(|substr| substr.trim().parse().unwrap())
        .collect();

    for key1 in 'a' as u8..='z' as u8 {
        for key2 in 'a' as u8..='z' as u8 {
            for key3 in 'a' as u8..='z' as u8 {
                let keys = vec![key1, key2, key3];

                let decoded: String = cyphertext
                    .iter()
                    .enumerate()
                    .map(|(i, n)| keys[i % keys.len()] ^ n)
                    .map(|n| char::from_u32(n as u32).unwrap())
                    .collect();

                if decoded
                    .as_bytes()
                    .windows(3) // length of "the"
                    .filter(|&substr| substr == "the".as_bytes())
                    .count() >= THE_THRESHOLD {

                    // println!("{}", decoded);
                    println!("{}", decoded
                        .as_bytes()
                        .into_iter()
                        .map(|&n| n as usize)
                        .sum::<usize>());

                    return Ok(());
                }

            }
        }
    }

    Ok(())
}

