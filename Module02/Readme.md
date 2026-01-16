# Module 02 Live Session



## Connection to 5001 / 5002 Material
- [x]  Can you please highlight what are the most important concepts from 5001 or 5002 that we should be rehearsing or building upon in this part of the course so far?

- [x] Could you think of additional sample problems pertaining to this week's topics that mix some fundamentals from 5001 to work through, showing us examples of how we are building up on what we've learned so far?


- Technically, it is all connected because programming is cumulative.... but let's cover a few examples.
* all of it but OOP

- loops
- condition statements
- input/output
- functions with parameters




## Stack and Pointers?
- [x] I would like to go over the memory stack
- [x] review passing pointers as args
- [x] Can we please go over pointers, addresses, and rules of thumb for when they're needed


-  Note: module 03 covers pointers, so if this feels a bit ahead, it is!


### Stack!

Stack == Short term memory.
- Local variables
- Function parameters
- Function return address
- Fast access
- Limited size

### Pointers!
Pointer == Address in memory.
- Variables have addresses
- Pointers store addresses
- Dereferencing pointers to access data
- Pointer arithmetic
- Used for dynamic memory management



## Commit and Industry Standards
- [ ] Can we talk about git commit messages and industry standards for them?


## Common Practices

** FOR CLASS expections

- commit frequently
- often after every function -

### Conventional Commit Messages
Not required for this class, but often expected in industry

https://www.conventionalcommits.org/en/v1.0.0/


- Format:
  ```
  <type>[optional scope]: <description>

  [optional body]

  [optional footer(s)]
  ```

Type options: fix:, feat:, build:, chore:, ci:, docs:, style:, refactor:, perf:, test:


### Pre-commit hooks

**NOT REQUIRED** but fairly common in industry.

- Automated scripts that run before each commit
- Enforce coding standards
- Run tests
- Prevent bad code from being committed
- Example from one of my projecsts [see example_pre-commit-config.yaml](example_pre-commit-config.yaml)





Basic of file for C:

```yaml
# Pre-commit hooks configuration
repos:
  - repo: local
    hooks:
      - id: clang-format
        name: clang-format
        entry: clang-format -i
        language: system
        types: [c, c++]
        files: \.(c|cpp|cc|cxx|h|hpp)$

  - repo: https://github.com/pre-commit/pre-commit-hooks
    rev: v4.5.0
    hooks:
      - id: trailing-whitespace
      - id: end-of-file-fixer
      - id: check-yaml
      - id: check-added-large-files
        args: ['--maxkb=2000']

  - repo: https://github.com/compilerla/conventional-pre-commit
    rev: v2.4.0
    hooks:
      - id: conventional-pre-commit
        stages: [commit-msg]
```
