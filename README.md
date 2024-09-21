[![website](https://github.com/keys-i/Assignments/actions/workflows/main.yml/badge.svg)](https://github.com/keys-i/Assignments/actions/workflows/main.yml)
# Assignments Documentation

Welcome to the documentation for the assignments. This repository contains MkDocs documentation for various assignments. Here you'll find information on how to build and deploy the documentation, as well as details about the assignments themselves.

## Overview

This repository uses MkDocs to generate documentation for assignments. MkDocs is a static site generator that's geared towards project documentation.

## Getting Started

### Prerequisites

Before you begin, ensure you have the following installed:

- [Python](https://www.python.org/downloads/)
- [pip](https://pip.pypa.io/en/stable/installation/)
- [MkDocs](https://mkdocs.org/#installation) (can be installed via pip)

### Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/keys-i/Assignments.git
   cd Assignments
   ```

2. **Install dependencies:**

   ```bash
   python -m pip install --upgrade pip
   pip install -r requirements.txt
   ```

### Building the Documentation

To build the documentation locally:

1. **Run the MkDocs build command:**

   ```bash
   mkdocs build
   ```

   This will generate the static site files in the `site` directory.

2. **Preview the documentation locally:**

   ```bash
   mkdocs serve
   ```

   This will start a local server and you can view the documentation at `http://127.0.0.1:8000/`.

## Deployment

The documentation is automatically deployed to GitHub Pages on push to the `main` branch. The workflow for deployment is defined in the GitHub Actions workflow file located in `.github/workflows/deploy.yml`.

### GitHub Actions Workflow

The GitHub Actions workflow includes steps for:

- Checking out the code.
- Setting up Python.
- Installing dependencies.
- Building the MkDocs site.
- Deploying the site to GitHub Pages.

## Contribution

If you want to contribute to this repository, please follow these steps:

1. **Fork the repository.**
2. **Create a new branch:**

   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Make your changes and commit them:**

   ```bash
   git add .
   git commit -m "Add your commit message here"
   ```

4. **Push to the branch:**

   ```bash
   git push origin feature/your-feature-name
   ```

5. **Create a pull request.**

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- MkDocs: [mkdocs.org](https://mkdocs.org/)
- GitHub Pages: [GitHub Pages](https://pages.github.com/)
