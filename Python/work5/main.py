TABLE_NAME = 'Benchmark'
MARGIN = 1         * ' '


def get_column_width(values: list):
    return max(map(lambda value: len(value), values))


def format_table(benchmarks, algos, results):
    # INIT MARGINs
    column_widths = []
    col1 = len(TABLE_NAME)
    column_widths.append(max(col1, get_column_width(benchmarks)))
    for i in range(len(algos)):
        width = len(algos[i])
        column = [str(a[i]) for a in results]
        column_widths.append(max(width, get_column_width(column)))

    # INIT TABLE HEADER
    row = f'|{MARGIN}{TABLE_NAME:<{column_widths[0]}}{MARGIN}|'
    for i in range(len(algos)):
        row += f'{MARGIN}{algos[i]:<{column_widths[i + 1]}}{MARGIN}|'
    print(row)
    print(f'|{"-" * (len(row) - 2)}|')

    # FILL TABLE
    for i in range(len(benchmarks)):
        row = f'|{MARGIN}{benchmarks[i]:<{column_widths[0]}}{MARGIN}|'
        for j in range(len(results[i])):
            row += f'{MARGIN}{results[i][j]:<{column_widths[j+1]}}{MARGIN}|'
        print(row)


format_table(['best_case', 'the worst case'],
             ['quick sort', 'merge sort', 'bubble sort'],
             [[1.23, 1.56, 2.0], [3.3, 2.9, 3.9]])
