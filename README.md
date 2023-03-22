### Run app:
```bash
mkdir build && cd build && cmake ../
make square_solver && ./src/square_solver
```

### Run tests:
```bash
mkdir build && cd build && cmake ../
make && cd tests/ && ctest; cd -
```
