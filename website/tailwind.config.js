module.exports = {
  purge: [
    './_includes/**/*.html',
    './_layouts/**/*.html',
    './_posts/*.html',
    './*.html',
  ],
  darkMode: false, // or 'media' or 'class'
  theme: {
    fontFamily: {
      'sans': ['Roboto', 'sans-serif']
    },
    extend: {
      colors: {
        'darker-gray': '#17171A',
        'dark-gray': '#242528',
        'light-gray': '#2E2E31',
        'lighter-gray': '#4C4E54',
        'lightest-gray': '#A3A3A3',
      },
      screens: {
        '3xl': '1800px',
      },
      listStyleType: {
        'lower-latin': 'lower-latin',
      },
    },
  },
  variants: {
    extend: {

    },
  },
  plugins: [],
};