# Media Catalogue

A console library catalogue in C++ holding books, films and magazines through a
single inheritance hierarchy. Written for CSCI 272 (Object-Oriented Programming in
C++) at New York City College of Technology, CUNY.

## Build and run

```bash
make
./catalogue
```

Requires a C++17 compiler. No external dependencies.

## What it does

```
1. Add a new item          4. List all items in library
2. Update an existing item 5. Exit program
3. View an item by ID
```

Each type carries its own fields — a book has an author, a film a director and
running time, a magazine an issue number — and each prints itself in its own format:

```
--- BOOKS ---
[1] The Pragmatic Programmer (1999) by Andrew Hunt

--- MOVIES ---
[1] Arrival (2016) directed by Denis Villeneuve, 116 min
```

## Design

```
Item (base)          title, year, getInfo()
├── Book             + author
├── Movie            + director, duration
└── Magazine         + issue number
```

`Item` holds what every catalogue entry shares and defines `getInfo()`. Each subclass
constructs its base with the common fields, adds its own, and overrides `getInfo()`
to describe itself. Adding a new media type means adding one class — no existing
code changes.

The point of the exercise was composing a base constructor from a derived one and
overriding behaviour rather than duplicating it, which is why the subclasses are
deliberately thin.

## Notes

Items live in memory only; the catalogue is empty again on restart. Persistence
wasn't part of the assignment.
