const node_num = 8;
const values = "1,3> <1,4> <1,6> <1,9> <1,10> <2,6> <2,8> <3,4> <3,5> <3,7> <3,10> <4,7> <6,10> <8,9> <9,10";
let nodes = [];
for(let i = 1; i <= node_num; i++) 
    nodes.push({ data: { id: i } });
let edges = [];
values.split("> <").map(value => {
    edges.push({ data: { source: value.split(",")[0], target: value.split(",")[1] } });
});

var cy = window.cy = cytoscape({
  container: document.getElementById('cy'),

  boxSelectionEnabled: false,
  autounselectify: true,

  style: [{
      selector: 'node',
      css: {
        'content': 'data(id)',
        'text-valign': 'center',
        'text-halign': 'center',
        'height': '60px',
        'width': '60px',
        'border-color': 'black',
        'border-opacity': '1',
        'border-width': '10px'
      }
    },
    {
      selector: '$node > node',
      css: {
        'padding-top': '10px',
        'padding-left': '10px',
        'padding-bottom': '10px',
        'padding-right': '10px',
        'text-valign': 'top',
        'text-halign': 'center',
        'background-color': '#bbb'
      }
    },
    {
      selector: 'edge',
      css: {
        'target-arrow-shape': 'triangle'
      }
    },
    {
      selector: ':selected',
      css: {
        'background-color': 'black',
        'line-color': 'black',
        'target-arrow-color': 'black',
        'source-arrow-color': 'black'
      }
    }
  ],

  elements: {
    nodes: nodes,
    edges: edges
  },

  layout: {
    name: 'dagre',
    padding: 5
  }
});
cy.unbind('click');
cy.bind('click', 'node', function(evt) {
  var edges = cy.collection();
  var dfs = cy.elements().dfs({
    roots: `#${evt.target.id()}`,
    visit: function(v, e, u, i, depth) {
      console.log('visit ' + v.id());
      if (e) edges = edges.add(e);
    },
    directed: false
  });

  console.log(dfs);
  cy.remove(edges);
});