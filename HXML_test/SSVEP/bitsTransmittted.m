%% Helper function to compute Mutual Information
function MI = bitsTransmittted(N, NN)
% Probability of not being transmitted correctly
p = N / NN;

% Joint probability distribution
pxy = [(1-p)/2, p/2; p/2, (1-p)/2];

% Marginal probabilities
px = sum(pxy, 2);
py = sum(pxy, 1);

% Entropies
hx = -sum(px .* log2(px + 1e-10));
hy = -sum(py .* log2(py + 1e-10));
hxy = -sum(pxy(:) .* log2(pxy(:) + 1e-10));

% Mutual Information
MI = NN * (hx + hy - hxy);

end