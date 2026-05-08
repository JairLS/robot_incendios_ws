from setuptools import find_packages
from setuptools import setup

setup(
    name='interfaces_tutorial',
    version='0.0.0',
    packages=find_packages(
        include=('interfaces_tutorial', 'interfaces_tutorial.*')),
)
