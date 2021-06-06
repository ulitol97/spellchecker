# Spellchecker (Levenshtein)

Demo of a spellchecker using [Levenshtein Distances](https://en.wikipedia.org/wiki/Levenshtein_distance) to correct the
user's input while suggesting new words.

This project implements the three most common ways of computing the edit distance between words:

1. [Recursive method](https://en.wikipedia.org/wiki/Levenshtein_distance#Recursive): inefficient and slowest way.
2. [Wagner–Fischer algorithm](https://en.wikipedia.org/wiki/Wagner%E2%80%93Fischer_algorithm) (full-matrix variant):
   enhancement over the recursive method using a matrix to cache repetitive computations.
3. Wagner–Fischer algorithm (single-row variant): further enhancement over the matrix method storing only the most
   significant data at a time.

The distance between words is later used to compare a given input against a dictionary and make suggestions, in the same
manner most modern text processors do. Word comparisons are run in parallel for enhanced performance.

## Compiling and running

### Getting the executable

- Build from source:
    1. Run `cmake .` inside the project folder to generate the _Makefile_.
    2. Run `make` inside the project folder to generate the binaries.
    3. Run the executable named _spellchecker_.


- Or download the linux executable from the [_bin_](https://github.com/ulitol97/spellchecker/tree/main/bin) folder.

### Program usage

The executable accepts several arguments:

- `-h`, `--help`: Show the program's help menu.
- `-d`, `--dict`: Relative path of the dictionary to be used. Defaults to `dictionary.txt`.
- `-s`, `--suggestions`: Number of words suggested by the spellchecker. Defaults to 5.

Once running, select the algorithm you want the spellchecker to use and start entering words to receive feedback.

## References

- Levenshtein distance algorithm samples:
    - [Recursive and matrix variants](https://en.wikipedia.org/wiki/Levenshtein_distance#Computing_Levenshtein_distance)
    - [Single row variant](https://rosettacode.org/wiki/Levenshtein_distance#C.2B.2B)
- [Dictionaries](http://www.gwicks.net/dictionaries.htm) used for testing
- [Inspiration](https://www.youtube.com/watch?v=Cu7Tl7FGigQ) for this demo project
