## Install dependencies

- install [Python 3](https://www.python.org/)
- install [CMake](https://cmake.org/)
- install the rest of the dependencies `pip install -r requirements.txt`

## Prepare the cmake cache

- Init the cmake cache `cmake -H. -Bbuild`


## Build

```
cmake --build build
```

## Using the notebook

- Emit benchmark output `build/<...>/bench.exe -t out.csv`
- `jupyter lab viz.ipynb`

## Reading

- [Celero](https://github.com/DigitalInBlue/Celero), the benchmarking framework used.
