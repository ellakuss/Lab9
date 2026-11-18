# Лабораторна робота №9 — варіант 12

## Склад
- `src/library` — обов'язкова частина: рефакторинг системи бібліотеки.
- `src/gilded_rose` — Kata Gilded Rose та індивідуальний тип `Perishable`.
- `tests/tests.cpp` — автоматизовані модульні перевірки без зовнішніх залежностей.
- `CMakeLists.txt` — збірка двох виконуваних цілей: програми та тестів.

## Збірка у Visual Studio 2026
Відкрийте папку `Lab9Variant12` через **File → Open → Folder**. Visual Studio має розпізнати `CMakeLists.txt`.

Альтернативно, у терміналі з каталогу проєкту:

```powershell
cmake -S . -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

Запуск програми (для звичайної одноконфігураційної збірки):

```powershell
.\build\Lab9Variant12.exe
```

Для Visual Studio multi-config шлях до exe може бути `build\Release\Lab9Variant12.exe`.

## Результати тестування
Тести перевіряють збереження книги, виклик сховища й сповіщення, правила звичайного товару, товару після SellIn, нижню межу якості, Aged Brie, Sulfuras, Backstage passes, Conjured та індивідуальний тип Perishable.
