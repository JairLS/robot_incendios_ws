from setuptools import find_packages
from setuptools import setup

setup(
    name='simulacion_ri',
    version='1.0.0',
    packages=find_packages(
        include=('simulacion_ri', 'simulacion_ri.*')),
)
