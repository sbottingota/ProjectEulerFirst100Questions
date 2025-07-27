using Combinatorics

const GRID_SIZE = 50;

# check if triangle is right angled
function is_right_angled(x1, y1, x2, y2, x3, y3)
    # check for invalid triangles
    if (x1, y1) == (x2, y2) || (x2, y2) == (x3, y3) || (x3, y3) == (x1, y1) ||
        x1 == x2 && x2 == x3 || y1 == y2 && y2 == y3
        return false
    end

    for ((x1, y1), (x2, y2), (x3, y3)) in permutations([(x1, y1), (x2, y2), (x3, y3)])
        v1 = (x1 - x2, y1 - y2)
        v2 = (x3 - x2, y3 - y2)

        # check if dot product is 0
        if v1[1] * v2[1] + v1[2] * v2[2] == 0
            return true
        end
    end

    false
end

count = 0

for x1 in 0:GRID_SIZE, y1 in 0:GRID_SIZE
    for x2 in x1:GRID_SIZE, y2 in 0:GRID_SIZE
        if x1 == x2 && y1 > y2
            continue
        end

        if is_right_angled(0, 0, x1, y1, x2, y2)
            # @printf("(%d %d) (%d %d)\n", x1, y1, x2, y2)
            global count += 1
        end
    end
end

println(count)

