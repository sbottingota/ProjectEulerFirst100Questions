const MIN: u32 = 1;
const MAX: u32 = 100_000;

const TARGET: u32 = 2_000_000;

fn triangle(n: u32) -> u32 {
    n * (n + 1) / 2
}

fn main() {
    let mut closest_area = 0_u32;
    let mut closest_value = 0_u32;

    for n in MIN..MAX {
        for m in MIN..MAX {
            let triangles = (triangle(n), triangle(m));

            if (triangles.0 * triangles.1).abs_diff(TARGET) < closest_value.abs_diff(TARGET) {
                closest_value = triangles.0 * triangles.1;
                closest_area = n * m;

            } else if (triangles.0 * triangles.1) > TARGET {
                break;
            }
        }
    }

    println!("{}", closest_area);
}

