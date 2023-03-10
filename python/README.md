# Running the tests in Python

To run the tests you will need pytest installed. You can do this either with poetry (see below), or using the requirements file in this folder.

## Install only required dependencies

    python -m pip install -r requirements.txt


## Install poetry and a large selection of dependencies

* Install [poetry](https://python-poetry.org/)
* Run `poetry install` once
* Run `poetry run pytest` to run the tests
