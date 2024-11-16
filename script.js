const selection = document.getElementById('selectionChart');
const insertion = document.getElementById('insertionChart');
const bubble = document.getElementById('bubbleChart');
const merge = document.getElementById('mergeChart');
const quick = document.getElementById('quickChart');
const heap = document.getElementById('heapChart');


new Chart(selection, {
  type: 'bar',
  data: {
    labels: ['100', '1000', '10000', '50000', '100000'],
    datasets: [{
      label: 'Seconds',
      data: [0.000017, 0.001290, 0.126846, 3.177811, 12.611614],
      borderWidth: 1
    }]
  },
  options: {
    scales: {
      y: {
        beginAtZero: true
      }
    }
  }
});

new Chart(insertion, {
  type: 'bar',
  data: {
    labels: ['100', '1000', '10000', '50000', '100000'],
    datasets: [{
      label: 'Seconds',
      data: [0.000008, 0.000461, 0.058486, 1.451379, 5.979643],
      borderWidth: 1
    }]
  },
  options: {
    scales: {
      y: {
        beginAtZero: true
      }
    }
  }
});

new Chart(bubble, {
  type: 'bar',
  data: {
    labels: ['100', '1000', '10000', '50000', '100000'],
    datasets: [{
      label: 'Seconds',
      data: [0.000023, 0.001628, 0.126379, 5.78459, 28.021646],
      borderWidth: 1
    }]
  },
  options: {
    scales: {
      y: {
        beginAtZero: true
      }
    }
  }
});

new Chart(merge, {
  type: 'bar',
  data: {
    labels: ['100', '1000', '10000', '50000', '100000'],
    datasets: [{
      label: 'Seconds',
      data: [0.000013, 0.000114, 0.001142, 0.007353, 0.012615],
      borderWidth: 1
    }]
  },
  options: {
    scales: {
      y: {
        beginAtZero: true
      }
    }
  }
});

new Chart(quick, {
  type: 'bar',
  data: {
    labels: ['100', '1000', '10000', '50000', '100000'],
    datasets: [{
      label: 'Seconds',
      data: [0.000002, 0.000210, 0.013309, 0.320284, 1.271484],
      borderWidth: 1
    }]
  },
  options: {
    scales: {
      y: {
        beginAtZero: true
      }
    }
  }
});

new Chart(heap, {
  type: 'bar',
  data: {
    labels: ['100', '1000', '10000', '50000', '100000'],
    datasets: [{
      label: 'Seconds',
      data: [0.000010, 0.000118, 0.001745, 0.007379, 0.019775],
      borderWidth: 1
    }]
  },
  options: {
    scales: {
      y: {
        beginAtZero: true
      }
    }
  }
});