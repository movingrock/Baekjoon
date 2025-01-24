// let input = require("fs").readFileSync("example.txt").toString().trim().split("\n");
let input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");

const [n, r, q] = input[0].split(" ").map(Number);

const graph = Array.from({ length: n + 1 }, () => []);
for (let i = 1; i < n; i++) {
  const [u, v] = input[i].split(" ").map(Number);
  graph[u].push(v);
  graph[v].push(u);
}

const queries = [];
for (let i = n; i < n + q; i++) {
  queries.push(Number(input[i]));
}

const subtree = Array(n + 1).fill(0);
const visited = Array(n + 1).fill(false);

const dfs = (node) => {
  visited[node] = true;
  subtree[node] = 1;

  for (const next of graph[node]) {
    if (!visited[next]) {
      subtree[node] += dfs(next);
    }
  }
  return subtree[node];
};

dfs(r);

const results = queries.map((query) => subtree[query]);
console.log(results.join("\n"));
